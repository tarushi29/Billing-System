#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Item {
    private:
        string name;
        int quantity;
        double price;
    public:
        Item(string n="", int q=0, double p=0.0) {
            name = n;
            quantity = q;
            price = p;
        }

        string getName() {
            return name;
        }

        int getQuantity() {
            return quantity;
        }

        double getPrice() {
            return price;
        }

        void setName(string n) {
            name = n;
        }

        void setQuantity(int q) {
            quantity = q;
        }

        void setPrice(double p) {
            price = p;
        }
};

class Bill {
    private:
        string customerName;
        string customerContact;
        Item *items;
        int itemCount;
    public:
        Bill(string name="", string contact="", int itemCount=0) {
            customerName = name;
            customerContact = contact;
            this->itemCount = itemCount;
            items = new Item[itemCount];
        }

        string getCustomerName() {
            return customerName;
        }

        string getCustomerContact() {
            return customerContact;
        }

        int getItemCount() {
            return itemCount;
        }

        Item getItem(int index) {
            return items[index];
        }

        void setCustomerName(string name) {
            customerName = name;
        }

        void setCustomerContact(string contact) {
            customerContact = contact;
        }

        void setItemCount(int count) {
            itemCount = count;
            items = new Item[itemCount];
        }

        void setItem(int index, Item item) {
            items[index] = item;
        }

        double getTotal() {
            double total = 0.0;
            for(int i = 0; i < itemCount; i++) {
                total += items[i].getPrice() * items[i].getQuantity();
            }
            return total;
        }
};

void displayBill(Bill bill) {
    cout << "Customer Name: " << bill.getCustomerName() << endl;
    cout << "Customer Contact: " << bill.getCustomerContact() << endl;
    cout << setw(15) << left << "Item Name" << setw(10) << left << "Quantity" << setw(10) << left << "Price" << endl;
    for(int i = 0; i < bill.getItemCount(); i++) {
        Item item = bill.getItem(i);
        cout << setw(15) << left << item.getName() << setw(10) << left << item.getQuantity() << setw(10) << left << item.getPrice() << endl;
    }
    cout << "Total: " << bill.getTotal() << endl;
}

void saveBill(Bill bill) {
    ofstream file("bill.txt");
    file << "Customer Name: " << bill.getCustomerName() << endl;
    file << "Customer Contact: " << bill.getCustomerContact() << endl;
    file << setw(15) << left << "Item Name" << setw(10) << left << "Quantity" << setw(10) << left << "Price" << endl;
    for(int i = 0; i < bill.getItemCount(); i++) {
        Item item = bill.getItem(i);
        file << setw(15) << left << item.getName() << setw(10) << left << item.getQuantity() << setw(10) << left << item.getPrice() << endl;
    }
    file << "Total: " << bill.getTotal() << endl;
    file.close();

}
int main() {
    // Create an instance of the Bill class
    Bill bill("John Doe", "john.doe@example.com", 3);

    // Create items and add them to the bill
    Item item1("Item 1", 2, 10.0);
    Item item2("Item 2", 3, 5.0);
    Item item3("Item 3", 1, 20.0);

    // Set items in the bill
    bill.setItem(0, item1);
    bill.setItem(1, item2);
    bill.setItem(2, item3);

    // Display the bill
    displayBill(bill);

    // Save the bill to a file
    saveBill(bill);

    return 0;
}





