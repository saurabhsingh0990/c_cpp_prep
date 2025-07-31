#include <iostream>
// | Concept                 | Example                           | Meaning                      |
// | ----------------------- | --------------------------------- | ---------------------------- |
// | Simple namespace        | `namespace Kitchen`               | Like a folder                |
// | Nested namespace        | `namespace Kitchen::Fridge`       | Subfolder inside a folder    |
// | Access nested function  | `Kitchen::Fridge::Juice()`        | Access function in subfolder |
// | Deeper nested namespace | `Kitchen::Stove::Cooking::Soup()` | Folder → Subfolder → Subsub  |

using namespace std;

// ✅ Namespace Kitchen acts like a big room
namespace Kitchen {

    // 🚪 Sub-namespace Fridge is like a section in Kitchen
    namespace Fridge {
        // 🍊 Juice function: pours juice
        void Juice() {
            cout << "Pouring orange juice" << endl;
        }

        // ✅ check function: checks if fridge is on
        void check(){
            cout << "Fridge is on" << endl;
        }
    }

    // 🔥 Sub-namespace Stove: another section in Kitchen
    namespace Stove {

        // 🍲 Nested namespace Cooking: part of Stove
        namespace Cooking {
            // 🍛 food function: cooks food
            void food(){
                cout << "cooking food" << endl;
            }

            // 🥣 Soup function: cooks soup
            void Soup(){
                cout << "cooking soup" << endl;
            }
        }

        // ✅ Check function: checks stove status
        void Check(){
            cout << "Stove is off" << endl;
        }
    }
}

int main() {
    // 🧪 Calling functions using nested namespaces
    Kitchen::Fridge::Juice();          // → "Pouring orange juice"
    Kitchen::Fridge::check();          // → "Fridge is on"

    Kitchen::Stove::Check();           // → "Stove is off"
    Kitchen::Stove::Cooking::food();   // → "cooking food"

    return 0;
}
