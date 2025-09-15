class CodeBrowser {
    constructor() {
        this.currentFile = null;
        this.fileTree = null;
        this.baseUrl = window.location.hostname === 'localhost' ? 
            '' : `https://raw.githubusercontent.com/${this.getRepoPath()}/main`;
        
        this.init();
    }

    getRepoPath() {
        // Extract username/repo from GitHub Pages URL
        const pathname = window.location.pathname;
        const parts = pathname.split('/').filter(part => part);
        if (parts.length > 0) {
            // Assuming GitHub Pages URL format: username.github.io/repo-name
            const username = window.location.hostname.split('.')[0];
            const repo = parts[0];
            return `${username}/${repo}`;
        }
        return 'saurabhsingh0990/c_cpp_prep '; // Fallback - replace with your actual repo
    }

    async init() {
        try {
            await this.loadFileTree();
            this.renderFileTree();
            this.setupEventListeners();
        } catch (error) {
            console.error('Failed to initialize:', error);
            this.showError('Failed to load file tree. Please check if fileTree.json exists.');
        }
    }

    async loadFileTree() {
        const response = await fetch(`${this.baseUrl}/fileTree.json`);
        if (!response.ok) {
            throw new Error(`HTTP ${response.status}: ${response.statusText}`);
        }
        this.fileTree = await response.json();
    }

    renderFileTree() {
        const container = document.getElementById('file-tree');
        container.innerHTML = this.buildTreeHTML(this.fileTree);
    }

    buildTreeHTML(tree, level = 0) {
        let html = '';
        
        for (const [name, item] of Object.entries(tree)) {
            if (item.type === 'folder') {
                html += `
                    <div class="tree-item" style="margin-left: ${level * 10}px">
                        <div class="tree-folder" onclick="this.parentElement.querySelector('.tree-children').style.display = this.parentElement.querySelector('.tree-children').style.display === 'none' ? 'block' : 'none'; this.querySelector('.folder-icon').classList.toggle('expanded')">
                            <span class="folder-icon">▶</span>
                            📁 ${name}
                        </div>
                        <div class="tree-children">
                            ${this.buildTreeHTML(item.children, level + 1)}
                        </div>
                    </div>
                `;
            } else {
                const extension = item.extension || '';
                html += `
                    <div class="tree-item" style="margin-left: ${level * 10}px">
                        <div class="tree-file" data-path="${item.path}" data-extension="${extension}" onclick="codeBrowser.loadFile('${item.path}', this)">
                            ${name}
                        </div>
                    </div>
                `;
            }
        }
        
        return html;
    }

    async loadFile(filePath, element) {
        try {
            // Update active state
            document.querySelectorAll('.tree-file').forEach(el => el.classList.remove('active'));
            element.classList.add('active');

            // Show loading
            const codeContent = document.getElementById('code-content');
            const codeDisplay = document.getElementById('code-display');
            const currentFileEl = document.getElementById('current-file');
            const copyBtn = document.getElementById('copy-btn');

            currentFileEl.textContent = `Loading ${filePath}...`;
            codeContent.textContent = 'Loading...';
            copyBtn.style.display = 'none';

            // Fetch file content
            const response = await fetch(`${this.baseUrl}/${filePath}`);
            if (!response.ok) {
                throw new Error(`Failed to load file: ${response.status}`);
            }

            const content = await response.text();
            const extension = this.getFileExtension(filePath);

            // Update UI
            currentFileEl.textContent = filePath;
            codeContent.textContent = content;
            
            // Apply syntax highlighting
            codeDisplay.className = `language-${this.mapExtensionToLanguage(extension)}`;
            Prism.highlightElement(codeContent);

            // Show copy button
            copyBtn.style.display = 'block';
            this.currentFile = { path: filePath, content };

        } catch (error) {
            console.error('Error loading file:', error);
            this.showError(`Failed to load ${filePath}: ${error.message}`);
        }
    }

    getFileExtension(filePath) {
        return filePath.split('.').pop().toLowerCase();
    }

    mapExtensionToLanguage(extension) {
        const languageMap = {
            'cpp': 'cpp',
            'c': 'c',
            'h': 'c',
            'hpp': 'cpp',
            'py': 'python',
            'js': 'javascript',
            'html': 'html',
            'css': 'css',
            'json': 'json',
            'md': 'markdown',
            'txt': 'text'
        };
        return languageMap[extension] || 'text';
    }

    setupEventListeners() {
        const copyBtn = document.getElementById('copy-btn');
        copyBtn.addEventListener('click', () => this.copyToClipboard());

        // Keyboard shortcuts
        document.addEventListener('keydown', (e) => {
            if (e.ctrlKey || e.metaKey) {
                if (e.key === 'c' && this.currentFile) {
                    e.preventDefault();
                    this.copyToClipboard();
                }
            }
        });
    }

    async copyToClipboard() {
        if (!this.currentFile) return;

        try {
            await navigator.clipboard.writeText(this.currentFile.content);
            const copyBtn = document.getElementById('copy-btn');
            const originalText = copyBtn.textContent;
            
            copyBtn.textContent = 'Copied!';
            copyBtn.style.background = '#28a745';
            
            setTimeout(() => {
                copyBtn.textContent = originalText;
                copyBtn.style.background = '#667eea';
            }, 2000);
        } catch (error) {
            console.error('Failed to copy:', error);
            alert('Failed to copy to clipboard');
        }
    }

    showError(message) {
        const currentFileEl = document.getElementById('current-file');
        const codeContent = document.getElementById('code-content');
        
        currentFileEl.textContent = 'Error';
        codeContent.textContent = message;
    }
}

// Initialize the application
const codeBrowser = new CodeBrowser();
