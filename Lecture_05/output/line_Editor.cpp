#include <iostream>
#include <string>

using namespace std;

// Function to display the current line and cursor position
void displayLine(const string& line, int cursor) {
    cout << "\nCurrent Line: " << line << endl;
    cout << "              ";
    for (int i = 0; i < cursor; ++i)
        cout << " ";
    cout << "^\n";
}

int main() {
    string line = "";       // Line being edited
    int cursor = 0;         // Cursor position

    int choice;
    char ch;

    do {
        displayLine(line, cursor);

        cout << "\nLine Editor Menu:\n";
        cout << "1. Insert Character\n";
        cout << "2. Delete Character\n";
        cout << "3. Move Cursor Left\n";
        cout << "4. Move Cursor Right\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> ch;
                line.insert(cursor, 1, ch);  // Insert character at cursor
                cursor++;                    // Move cursor forward
                break;

            case 2:
                if (cursor > 0) {
                    line.erase(cursor - 1, 1);  // Delete character before cursor
                    cursor--;
                } else {
                    cout << "Nothing to delete!\n";
                }
                break;

            case 3:
                if (cursor > 0) {
                    cursor--;
                } else {
                    cout << "Cursor is at the beginning!\n";
                }
                break;

            case 4:
                if (cursor < line.length()) {
                    cursor++;
                } else {
                    cout << "Cursor is at the end!\n";
                }
                break;

            case 5:
                cout << "\nFinal Edited Line: " << line << endl;
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
