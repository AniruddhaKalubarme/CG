#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
    string name, dob, phone;
    bool operator<(Record other) { return name < other.name; }
};

void display(vector<Record> records) {
    for (auto rec : records)
        cout << "Name: " << rec.name << ", DOB: " << rec.dob << ", Phone: " << rec.phone << endl;
}

int main() {
    vector<Record> records = {{"Bob", "1985-10-30", "9876543210"},
                             {"Alice", "1990-05-15", "1234567890"},
                             {"Charlie", "1992-07-20", "5556667777"}};

    // Sort records by name
    sort(records.begin(), records.end());
    cout << "Sorted Records:\n";
    display(records);

    // Search by name
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    bool found = false;
    for (auto rec : records) {
        if (rec.name == searchName) {
            cout << "Found: Name: " << rec.name << ", DOB: " << rec.dob << ", Phone: " << rec.phone << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found!" << endl;

    return 0;
}
