// DSTR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;
#include <string>

void insertatbeginning(int id, string type, string description, int quantity, string colour, string size, double price);
void insertatend(int id, string type, string description, int quantity, string colour, string size, double price);

void insertintosortedlist(int id, string type, string description, int quantity, string colour, string size, double price);
void deleteatbeginning();
void deleteatend();
void deleteatvalue();
void deleteatbeginningorder();
void deleteatendorder();
void deleteatvalueorder();
void deleteatbeginningorderdelivery();
void deleteatendorderdelivery();
void deleteatvalueorderdelivery();
void display();
void showindex(int index);
void showindexorderdelivery(int index);
void showindexorder(int index);
void displayorder();
void displayorderdelivery();
void customer();
void admin();
void search();
double findprice(int id, int quantity);
string findtype(int id);
void insertatorderdeliverybeginning(int id, string name, string type, string contactno, string address, int quantity, double price);
void insertatorderdeliveryend(int id, string name, string type, string contactno, string address, int quantity, double price);
void insertatorderdeliverysorted(int id, string name, string type, string contactno, string address, int quantity, double price);
void insertatorderbeginning(int id, string name, string type, int quantity, double price);
void insertatorderend(int id, string name, string type, int quantity, double price);
void insertatordersorted(int id, string name, string type, int quantity, double price);
void updateorderdelivery(int id);
void login();
int k = 1;
int l = 1;


struct node {
	int id,quantity;
	double price;
	string type, description, colour, size;

	struct node* next;
	struct node* back;
}*head,*tail;




struct order {
	int id;
	string name, type;
	int quantity;
	double price;

	struct order* ordernext;
	struct order* orderback;



}*orderhead, * ordertail;

struct orderdelivery {
	int id;
	string name, type,address, contactno;
	int quantity;
	double price;

	struct orderdelivery* orderdeliverynext;
	struct orderdelivery* orderdeliveryback;



}*orderdeliveryhead, *orderdeliverytail;
// main function where cloth linked list is initialized
int main()
{
	
	insertintosortedlist(1, "Shirt", "Quality shirt manufactured in Malaysia", 30, "Black", "M", 7);
	insertintosortedlist(2, "Jeans", "Blue jeans with big pockets", 30, "Blue", "XS", 3);
	insertintosortedlist(3, "Shorts", "Red shorts with no pockets", 30, "Red", "S", 1);
	insertintosortedlist(4, "Skirt", "Purple long skirt", 30, "Purple", "L", 8);
	insertintosortedlist(5, "Slacks", "Long Brown Slacks", 30, "Brown", "XL", 10);

	login();



	}






//Login function

void login() {
	int option;
	string customeruser, customerpass, adminuser, adminpass;
	bool loginsuccess = false;

	cout << "1.Customer Login\n";
	cout << "2.Admin Login\n";
	
	cin >> option;
	


	while (loginsuccess == false) {




		if (option == 1) {
			cout << "Enter customer username: \n";
			cin >> customeruser;

			cout << "Enter customer password: \n";
			cin >> customerpass;

			if (customeruser == "jack" && customerpass == "jack")
			{
				cout << "Login Successful \n";
				loginsuccess = true;
				customer();

			}
			if (customeruser == "mac" && customerpass == "mac")
			{
				cout << "Login Successful \n";
				loginsuccess = true;
				customer();

			}
			if (customeruser == "jim" && customerpass == "jim")
			{
				cout << "Login Successful \n";
				loginsuccess = true;
				customer();

			}
			if (customeruser == "mary" && customerpass == "mary")
			{
				cout << "Login Successful \n";
				loginsuccess = true;
				customer();

			}
			if (customeruser == "max" && customerpass == "max")
			{
				cout << "Login Successful \n";
				loginsuccess = true;
				customer();

			}
			else {
				cout << "Incorrect credential, please try again \n";
			}


		}

		else if (option == 2) {
			cout << "Enter admin username: \n";
			cin >> adminuser;

			cout << "Enter admin password: \n";
			cin >> adminpass;

			if (adminuser == "admin" && adminpass == "admin")
			{
				cout << "Login Successful \n";
				loginsuccess = true;

				admin();




			}
			else {
				cout << "Incorrect credential, please try again \n";
			}


		}

	}
}
// Customer page 
void customer() {


	int id, option, quantity;
	
	double price, payable, change;
	string clothname, type;
	bool s = true;
	bool m = true;
	string choice;
	string name, address, contactno;


	while (s == true)
	{
		cout << "1. View list of cloths \n";
		cout << "2. Search for cloths \n";
		cout << "3. Order Cloths \n";
		cout << "4. Move back and forth between Cloths \n";
		cout << "5. Logs out \n";
		cin >> option;

		if (option == 1) {
			display();

		}


		if (option == 2) {


			search();
		}


		if (option == 3) {
			display();

			cout << "Enter the cloth's id you would like to purchase: ";
			cin >> id;

			cout << "Enter the quantity you would like to purchase: ";
			cin >> quantity;

			price = findprice(id, quantity);
			cout << "The total price is RM " << price << endl;

			clothname = findtype(id);
		

			cout << "Do you need delivery for this order? (Y/N): ";
			cin >> choice;

			if (choice == "Y") {

				id = k;
				price = price + 50;

				cout << "Enter your name: ";
				
				cin >> name;
				cout << "Enter your address: ";
				cin >>address;
				cout << "Enter your contact no: ";
				cin >>contactno;

				while (m == true) {
					cout << "The total price is RM " << price << endl;
					cout << "Enter your payable amount: ";
					cin >> payable;

					change = payable - price;


					if (change > 0) {
						k = k + 1;
						cout << "Order successful, your change is: RM " << change<<endl;
						insertatorderdeliverysorted(id, name, clothname, contactno, address, quantity, price);
						displayorderdelivery();
						break;
					}

					else if (change < 0) {
						cout << "Your payment is not enough, please try again "<<endl;


					}
				}
			}




			else if (choice == "N") {

				id = l;

				while (m == true) {
					cout << "Enter your name: ";
					cin >> name;
					cout << "The total price is RM " << price<<endl;
					cout << "Enter your payable amount: RM ";
					cin >> payable;

					change = payable - price;


					if (change > 0) {
						l = l + 1;
						cout << "Order successful, your change is: RM " << change << endl;
						insertatordersorted(id, name, clothname, quantity, price);
						displayorder();
						break;

					}

					else if (change < 0) {
						cout << "Your payment is not enough, please try again ";

					}

				}
			}
		}

		if (option == 4) {
			int i = 1;
			int options;
			bool m = true;
			showindex(i);
			while (m == true) {
				

				cout << "1. Go to next cloth \n";
				cout << "2. Go to previous cloth \n";
				cout << "3. Back to Menu \n";
				cin >> options;

				if (options == 1) {
					i = i + 1;
					showindex(i);
					
				}
				if (options == 2) {
					i = i - 1;
					showindex(i);
				}
				if (options == 3) {
					break;
				}

			}
			



		}





		if (option == 5) {

			login();


		}
	}
}
	
	
	




// Admin Page

void admin() {
	int id, quantity,option;
	double price;
	string type,colour,size,description;
	bool a = true;
	while (a == true) {


		cout << "1.Add new clothes \n";
		cout << "2.View Cloths \n";
		cout << "3.Remove Cloths \n";
		cout << "4.View orders \n";
		cout << "5. Move back and forth between Orders(No delivery) \n";
		cout << "6. Move back and forth between Orders(Delivery) \n";
		cout << "7.Remove Orders(No delivery) \n";
		cout << "8. Remove Orders(Delivery) \n";
		cout << "9. Modify Orders with Delivery \n";
		cout << "10.Logs out \n";
		cin >> option;

		if (option == 1) {

			cout << "Enter cloth's id: ";
			cin >> id;
			
			
			cout << "Enter cloth's type: ";
			cin >> type;

			cout << "Enter cloth's description: ";
			cin >> description;

			cout << "Enter cloth's quantity: ";
			cin >> quantity;

			cout << "Enter cloth's colour: ";
			cin >> colour;

			cout << "Enter cloth's size: ";
			cin >> size;

			cout << "Enter cloth's price: ";
			cin >> price;

			insertintosortedlist(id, type, description,quantity,colour,size,price);

		}
		if (option == 2) {
			display();
		}
		if (option == 3) {

			display();


			deleteatvalue();

		}
		if (option == 4) {
			displayorderdelivery();
			displayorder();
		

		}

		if (option == 5) {
			int i = 1;
			int options;
			bool m = true;
			showindexorder(i);
			while (m == true) {


				cout << "1. Go to next order \n";
				cout << "2. Go to previous order \n";
				cout << "3. Back to menu \n";
				cin >> options;

				if (options == 1) {
					i = i + 1;
					showindexorder(i);

				}
				if (options == 2) {
					i = i - 1;
					showindexorder(i);
				}
				if (options == 3) {
					break;
				}

			}

		}

		if (option == 6) {
			int i = 1;
			int options;
			bool m = true;
			showindexorderdelivery(i);
			while (m == true) {


				cout << "1. Go to next order \n";
				cout << "2. Go to previous order \n";
				cout << "3. Back to Menu \n";
				cin >> options;

				if (options == 1) {
					i = i + 1;
					showindexorderdelivery(i);

				}
				if (options == 2) {
					i = i - 1;
					showindexorderdelivery(i);
				}
				if (options == 3) {
					break;
				}

			}
		}

		if (option == 7) {
			displayorder();
			deleteatvalueorder();

		}

		if (option == 8) {
			displayorderdelivery();
			deleteatvalueorderdelivery();
		}

		if (option == 9) {
			displayorderdelivery();
			cout << "Enter the order id to be edited: ";
			cin >> id;
			updateorderdelivery(id);
				

		}
		if (option == 10) {

			login();

		}



	}


}

// Insert at beginning of cloth's linked list
void insertatbeginning(int id, string type, string description, int quantity, string colour, string size, double price)
{
	node* newnode = new node;
	newnode->id = id;
	newnode->type = type;
	newnode->description = description;
	newnode->quantity = quantity;
	newnode->colour = colour;
	newnode->size = size;
	newnode->price = price;
	
	newnode->next = NULL;
	newnode->back = NULL;

	if (head == NULL) {
		head = tail = newnode;
	}

	else {
		newnode->next = head;
		head = newnode;
		newnode->next->back = newnode;
	}


}
// Insert at the end of cloth's linked list
void insertatend(int id,string type,string description,int quantity,string colour,string size,double price)
{
	node* newnode = new node;	
	
	newnode->id = id;
	newnode->type = type;
	newnode->description = description;
	newnode->quantity = quantity;
	newnode->colour = colour;
	newnode->size = size;
	newnode->price = price;

	newnode->next = NULL;
	newnode->back = NULL;

	if (head == NULL) {
		head = tail = newnode;
	}

	else {
		newnode->back = tail;
		tail->next = newnode;
		tail = newnode;
	}


}
// Insert at beginning of order with delivery linked list
void insertatorderdeliverybeginning(int id, string name, string type, string contactno, string address, int quantity, double price)
{
	orderdelivery* newnode = new orderdelivery;

	newnode->id = id;
	newnode->name = name;
	newnode->type = type;
	newnode->contactno = contactno;
	newnode->address = address;
	newnode->quantity = quantity;
	newnode->price = price;

	newnode->orderdeliverynext = NULL;
	newnode->orderdeliveryback = NULL;

	if (orderdeliveryhead == NULL) {
		orderdeliveryhead = orderdeliverytail = newnode;
	}

	else {
		newnode->orderdeliverynext = orderdeliveryhead;
		orderdeliveryhead = newnode;
		newnode->orderdeliverynext->orderdeliveryback = newnode;
	}


}
// Insert at the end of order with delivery linked list
void insertatorderdeliveryend(int id,string name, string type, string contactno, string address, int quantity, double price)
{
	orderdelivery* newnode = new orderdelivery;

	newnode->id = id;
	newnode->name = name;
	newnode->type = type;
	newnode->contactno = contactno;
	newnode->address = address;
	newnode->quantity = quantity;
	newnode->price = price;

	newnode->orderdeliverynext = NULL;
	newnode->orderdeliveryback = NULL;

	if (orderdeliveryhead== NULL) {
		orderdeliveryhead = orderdeliverytail = newnode;
	}

	else {
		newnode->orderdeliveryback = orderdeliverytail;
		orderdeliverytail->orderdeliverynext = newnode;
		orderdeliverytail = newnode;
	}


}
// Insert at sorted order with delivery linked list
void insertatorderdeliverysorted(int id, string name, string type, string contactno, string address, int quantity, double price)
{
	orderdelivery* newnode = new orderdelivery;
	orderdelivery* previous = new orderdelivery;
	newnode->id = id;
	newnode->name = name;
	newnode->type = type;
	newnode->contactno = contactno;
	newnode->address = address;
	newnode->quantity = quantity;
	newnode->price = price;

	newnode->orderdeliverynext = NULL;
	newnode->orderdeliveryback = NULL;

	if (orderdeliveryhead == NULL) {
		orderdeliveryhead = orderdeliverytail = newnode;
	}

	else if (price < orderdeliveryhead->price) {
		insertatorderdeliverybeginning(id, name, type, contactno, address,  quantity,  price);
	}

	else {

		orderdelivery* temp = orderdeliveryhead;
		while (temp != NULL) {
			if (price > orderdeliveryhead->price)
			{
				previous = temp;
			}
			else {
				break;
			}
			temp = temp->orderdeliverynext;
		}
		if (temp == NULL)
		{
			insertatorderdeliveryend(id, name, type, contactno, address,  quantity,  price);
		}
		else {
			newnode->orderdeliverynext = previous->orderdeliverynext;
			previous->orderdeliverynext->orderdeliveryback = newnode;
			previous->orderdeliverynext = newnode;
			newnode->orderdeliveryback = previous;
		}


	}
}
// Insert at beginning of order with no delivery linked list
void insertatorderbeginning(int id, string name, string type, int quantity, double price)
{
	order* newnode = new order;

	newnode->id = id;
	newnode->name = name;
	newnode->type = type;

	newnode->quantity = quantity;
	newnode->price = price;

	newnode->ordernext = NULL;
	newnode->orderback = NULL;

	if (orderhead == NULL) {
		orderhead = ordertail = newnode;
	}

	else {
		newnode->ordernext = orderhead;
		orderhead = newnode;
		newnode->ordernext->orderback = newnode;
	}


}
// Insert at end of order with no delivery linked list
void insertatorderend(int id,string name, string type, int quantity, double price)
{
	order* newnode = new order;

	newnode->id = id;
	newnode->name = name;
	newnode->type = type;
	
	newnode->quantity = quantity;
	newnode->price = price;

	newnode->ordernext = NULL;
	newnode->orderback = NULL;

	if (orderhead == NULL) {
		orderhead = ordertail = newnode;
	}

	else {
		newnode->orderback = ordertail;
		ordertail->ordernext = newnode;
		ordertail = newnode;
	}


}
// Insert at sorted order with no delivery linked list
void insertatordersorted(int id, string name, string type, int quantity, double price)
{
	order* newnode = new order;
	order* previous = new order;
	newnode->id = id;
	newnode->name = name;
	newnode->type = type;

	newnode->quantity = quantity;
	newnode->price = price;

	newnode->ordernext = NULL;
	newnode->orderback = NULL;

	if (orderhead == NULL) {
		orderhead = ordertail = newnode;
	}

	else if (price < orderhead->price) {
		insertatorderbeginning(id, name, type, quantity, price);
	}

	else {

		order* temp = orderhead;
		while (temp != NULL) {
			if (price > orderhead->price)
			{
				previous = temp;
			}
			else {
				break;
			}
			temp = temp->ordernext;
		}
		if (temp == NULL)
		{
			insertatorderend(id, name, type, quantity, price);
		}
		else {
			newnode->ordernext = previous->ordernext;
			previous->ordernext->orderback = newnode;
			previous->ordernext = newnode;
			newnode->orderback = previous;
		}


	}
}

// Insert at sorted cloth linked list
void insertintosortedlist(int id, string type, string description, int quantity, string colour, string size, double price)
{
	node* newnode = new node;
	node* previous= new node;
	newnode->id = id;
	newnode->type = type;
	newnode->description = description;
	newnode->quantity = quantity;
	newnode->colour = colour;
	newnode->size = size;
	newnode->price = price;

	newnode->next = NULL;
	newnode->back = NULL;

	if (head == NULL) {
		head = tail = newnode;
	}

	else if (price < head->price ) {	
		insertatbeginning(id,type,description,quantity,colour,size,price);
		}

	else {

		node *temp = head;
		while (temp != NULL) {
			if (price > head->price)
			{
				previous = temp;
			}
			else {
				break;
			}
			temp = temp->next;
		}
		if (temp == NULL)
		{
			insertatend(id, type, description, quantity, colour, size, price);
		}
		else {
			newnode->next = previous->next;
			previous->next->back = newnode;
			previous->next = newnode;
			newnode->back = previous;
		}


	}
}
// Delete at beginning of cloth linked list
void deleteatbeginning() {
	node *temp = head;
	head->next->back = NULL;
	head = head->next;
	cout << "Item to be deleted: " <<" Cloth id: "<< temp->id <<" Cloth type: "<< temp->type <<" Cloth description: "<< temp->description <<" Cloth quantity: "<< temp->quantity <<" Cloth colour: "<< temp->colour<<" Cloth size: "<<temp->size<<" Cloth price: "<<temp->price<<"\n";
	delete temp;
		
}
// Delete at end of cloth linked list
void deleteatend() {
	node *temp = tail;
    tail->back->next = NULL;
	tail = tail->back;
	cout << "Item to be deleted: " << " Cloth id: " << temp->id << " Cloth type: " << temp->type << " Cloth description: " << temp->description << " Cloth quantity: " << temp->quantity << " Cloth colour: " << temp->colour << " Cloth size: " << temp->size << " Cloth price: " << temp->price << "\n";
	delete temp;

}
// Display cloth linked list
void display() {

	node * temp = head;
	if (temp == NULL)
	{
		cout << "List is empty" << endl;
	}
	else {
		
		while (temp != NULL) {
			cout << "Cloth id: " << temp->id << " Type: " << temp->type << " Description: " << temp->description << " Quantity: " << temp->quantity << " Colour: " << temp->colour << " Size: " << temp->size << " Price: " << temp->price<<"\n";
			temp = temp->next;
		}
		cout << endl;
	}
}
// Display order with no delivery linked list
void displayorder() {

	order* temp = orderhead;
	if (temp == NULL)
	{
		cout << "List is empty" << endl;
	}
	else {

		while (temp != NULL) {
			cout << "Order id: "<<temp->id<<" Customer Name: "<<temp->name<<" Cloth's type: "<<temp->type<<" Quantity: "<<temp->quantity<<" Price: "<<temp->price<<endl;
			temp = temp->ordernext;
		}
		cout << endl;
	}
}
// Display order with delivery linked list
void displayorderdelivery() {

	orderdelivery* temp = orderdeliveryhead;
	if (temp == NULL)
	{
		cout << "List is empty" << endl;
	}
	else {

		while (temp != NULL) {
			cout << "Order id: " << temp->id << " Customer Name: " << temp->name << " Cloth's type: " << temp->type <<" Address: "<<temp->address<<" Contact No: "<<temp->contactno<<" Quantity: " << temp->quantity << " Price: " << temp->price<<endl;
			temp = temp->orderdeliverynext;
		}
		cout << endl;
	}
}
// Delete cloth based on cloth's id given
void deleteatvalue() {
	node *temp = new node;
	node *previous = new node;
	int cid;
	cout << "Enter cloth's id to delete: \n";
	cin >> cid;
	temp = head;
	while (temp->id != cid) {
		previous= temp;
		temp = temp->next;

	}
	if (temp == tail) {
		deleteatend();

	}
	else if (temp == head) {
		deleteatbeginning();
	}
	else {
		previous->next = previous->next->next;
		temp->next->back = previous;
		delete temp;
	}

}
// Delete at beginning of order with no delivery linked list
void deleteatbeginningorder() {
	order* temp = orderhead;
	orderhead->ordernext->orderback = NULL;
	orderhead = orderhead->ordernext;
	cout << "Item to be deleted: " <<" Order id: "<< temp->id <<" Customer's name "<< temp->name <<" Cloth's type: "<< temp->type <<" Cloth's quantity: "<< temp->quantity <<" Order's price: "<< temp->price<<"\n";
	delete temp;

	
}
// Delete at end of order with no delivery linked list
void deleteatendorder() {
	order* temp = ordertail;
	ordertail->orderback->ordernext = NULL;
	ordertail = ordertail->orderback;
	cout << "Item to be deleted: " << " Order id: " << temp->id << " Customer's name " << temp->name << " Cloth's type: " << temp->type << " Cloth's quantity: " << temp->quantity << " Order's price: " << temp->price << "\n";
	delete temp;

}
// Delete order with no delivery
void deleteatvalueorder() {
	order* temp = new order;
	order* previous = new order;
	int cid;
	cout << "Enter order's id to delete: \n";
	cin >> cid;
	temp = orderhead;
	while (temp->id != cid) {
		previous = temp;
		temp = temp->ordernext;

	}
	if (temp == ordertail) {
		deleteatendorder();

	}
	else if (temp == orderhead) {
		deleteatbeginningorder();
	}
	else {
		previous->ordernext = previous->ordernext->ordernext;
		temp->ordernext->orderback = previous;
		delete temp;
	}

}
// Delete beginning of order with delivery linked list
void deleteatbeginningorderdelivery() {
	orderdelivery* temp = orderdeliveryhead;
	orderdeliveryhead->orderdeliverynext->orderdeliveryback = NULL;
	orderdeliveryhead = orderdeliveryhead->orderdeliverynext;
	cout << "Item to be deleted: " <<" Order ID: "<< temp->id <<" Customer's name: "<< temp->name <<" Cloth's type: "<< temp->type <<" Customer's address: "<< temp->address<<" Customer's contactno: "<<temp->contactno<< " Cloth's quantity: "<<temp->quantity <<" Order price: "<< temp->price << "\n";
	delete temp;

}
//Delete end of order with delivery linked list
void deleteatendorderdelivery() {
	orderdelivery* temp = orderdeliverytail;
	orderdeliverytail->orderdeliveryback->orderdeliverynext = NULL;
	orderdeliverytail = orderdeliverytail->orderdeliveryback;
	cout << "Item to be deleted: " << " Order ID: " << temp->id << " Customer's name: " << temp->name << " Cloth's type: " << temp->type << " Customer's address: " << temp->address << " Customer's contactno: " << temp->contactno << " Cloth's quantity: " << temp->quantity << " Order price: " << temp->price << "\n";

	delete temp;

}
// Delete order with delivery
void deleteatvalueorderdelivery() {
	orderdelivery* temp = new orderdelivery;
	orderdelivery* previous = new orderdelivery;
	int cid;
	cout << "Enter order's id to delete: ";
	cin >> cid;
	temp = orderdeliveryhead;
	while (temp->id != cid) {
		previous = temp;
		temp = temp->orderdeliverynext;

	}
	if (temp == orderdeliverytail) {
		deleteatendorderdelivery();

	}
	else if (temp == orderdeliveryhead) {
		deleteatbeginningorderdelivery();
	}
	else {
		previous->orderdeliverynext = previous->orderdeliverynext->orderdeliverynext;
		temp->orderdeliverynext->orderdeliveryback = previous;
		delete temp;
	}

}
// Search for cloth's type based on cloth's type
void search()

{
	string description;
	cout << " Enter the cloth's description you want to search ";
	cin.ignore();
	getline(cin, description);

	node* temp = head;

	while (temp->next != NULL && temp->description.find(description) == string::npos)
	{
		temp = temp->next;
		
		
	}
	if (temp->description.find(description)!=string::npos) {
		cout <<" Cloth's ID "<< temp->id << " Cloth's type: "<< temp->type <<" Cloth's description: "<<" Cloth's description: "<< temp->description <<" Cloth's quantity: "<< temp->quantity << " Cloth's colour: "<<temp->colour << " Cloth's size: "<<temp->size <<" Cloth's price: "<< temp->price<<endl;

	}
	else {
		cout << "nothing was found" << endl;
	}
	
	


}
// Return total price of order after calculation
double findprice(int id, int quantity)

{
	string clothtype;
	double price;

	node* temp = head;

	while (temp->next != NULL && id != temp->id)
	{
		temp = temp->next;


	}
	if (temp->id == id) {
	return price = temp->price * quantity;
}
}
string findtype(int id)

{
	string clothtype;


	node* temp = head;

	while (temp->next != NULL && id != temp->id)
	{
		temp = temp->next;


	}
	if (temp->id == id) {
		return clothtype=temp->type;
	}
}

void showindex(int index) {


	node* temp = head;

	while (temp->next != NULL && index != temp->id)
	{
		temp = temp->next;


	}
	if (temp->id == index) {
		cout <<" Cloth's ID: "<< temp->id<<" Cloth's type: " << temp->type<<" Cloth's description: " << temp->description<<" Cloth's quantity: " << temp->quantity<<" Cloth's colour: " << temp->colour<<" Cloth's size " << temp->size<<" Cloth's price: " << temp->price<< "\n";

	}
	else {
		cout << "You have reach the end of the clothing list"<<endl;
	}

}

void showindexorder(int index) {


	order* temp = orderhead;

	while (temp->ordernext != NULL && index != temp->id)
	{
		temp = temp->ordernext;


	}
	if (temp->id == index) {
		cout <<" Order ID: "<< temp->id << " Buyer's name: " << temp->name << " Cloth's type: " << temp->type << " Order quantity: " << temp->quantity << " Order cost: " << temp->price  << "\n";

	}
	else {
		cout << "You have reach the end of the clothing list "<<endl;
	}

}

void showindexorderdelivery(int index) {


	orderdelivery* temp = orderdeliveryhead;

	while (temp->orderdeliverynext != NULL && index != temp->id)
	{
		temp = temp->orderdeliverynext;


	}
	if (temp->id == index) {
		cout << " Order ID: " << temp->id << " Buyer's name: " << temp->name << " Cloth's type: " << temp->type << " Delivery Address: " <<temp->address<<" Buyer's contact number: "<<temp->contactno<<" Order quantity: " << temp->quantity << " Order cost: " << temp->price << "\n";

	}
	else {
		cout << "You have reach the end of the clothing list "<<endl;
	}

}
// Modify order with delivery linked list
void updateorderdelivery(int id) {
	orderdelivery* temp = orderdeliveryhead;

	while (temp->orderdeliverynext != NULL && id != temp->id)
	{
		temp = temp->orderdeliverynext;

	}

		if (temp->id = id) {
			cout << "Enter updated customer's name: ";
			cin >> temp->name;
			cout << "Enter updated delivery address: ";
			cin >> temp->address;
			cout << "Enter updated customer's contact number: ";
			cin >> temp->contactno;

	}
		else {
			cout << "No data can be found";
		}

	
}