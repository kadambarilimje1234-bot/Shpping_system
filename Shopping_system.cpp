#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure for Product
struct Product {
    string name;
    int price;
    int quantity = 0; // Default quantity is 0
};

// Base class for a Makeup Category
class MakeupCategory {
	protected:
	    vector<Product> products;
	
	public:
		//adding to vector
	    void addProduct(const string& name, int price) {
	        products.push_back({name, price});
	    }
	
		//displaying product
	    void displayProducts() {
	        cout << "\n";
	        for (size_t i = 0; i < products.size(); ++i) {
	            cout << i + 1 << ". " << products[i].name << " - Rs. " << products[i].price << "\n";
	        }
	    }
		
		//choise and quantity
	    void purchaseProduct(int index, int quantity) {
	        if (index < 1 || index > products.size()) {
	            cout << "Invalid choice!\n";
	            return;
	        }
	        products[index - 1].quantity += quantity;
	        cout << "Added " << quantity << " of " << products[index - 1].name << " to cart.\n";
	    }
		
		//total calculation
	    int calculateSubtotal() {
	        int subtotal = 0;
	        for (const auto& product : products) {
	            subtotal += product.price * product.quantity;
	        }
	        return subtotal;
	    }
	    
	    int displayCategoryBill(MakeupCategory& category){
			int subtotal = 0;
			bool hasitems = false;

			for(const auto& product : category.products){
				if(product.quantity > 0) {
					hasitems = true;
					cout << product.name << " * Qty: " << product.price << "*" << product.quantity;
					cout << " = " << product.quantity * product.price << "rs.\n";
					subtotal += product.quantity * product.price;
				}
			}

			if(hasitems) {
				cout << "No items purchased in this category.\n";
			}
			
			cout << "Subtotal: " << subtotal << "rs.\n";
			return subtotal;
		}
};

// Derived class for Eye Makeup
class EyeMakeup : public MakeupCategory {
	public:
	    void EyeShadow() {
	        addProduct("Lakme Absolute Illuminating Eye Shadow Palette - French Rose", 995);
	        addProduct("Lakme Absolute illuminating Eye shadow palette-Royal Persia", 995);
	        addProduct("Lakme Absolute illuminating Eye shadow palette-silver", 995);
			addProduct("Lakme Absolute illuminating Eye shadow palette-Gold", 995);
			addProduct("Lakme 9to5 Eye Quarter - Tanjore Rush", 600);
			addProduct("Lakme 9to5 Eye Quarter - Desert Rose", 600);
	        addProduct("Lakme 9to5 Eye Quarter - Silk Route", 600);
	    }
	    
	    void EyeLiner() {
	    	addProduct("Lakme Absolute shine line", 450);
	    	addProduct("Lakme Absolute precision Eye Artist Kajal", 850);
	    	addProduct("Lakme 9to5 black impact liner", 225);
	    	addProduct("Lakme Absolute gel addict", 800);
	    	addProduct("Lakme Absolute forever silk eyeliner", 450);
	    	addProduct("Lakme eyeconic Kajal", 275);
	    	addProduct("Lakme Absolute precision liner", 475);
	    	addProduct("Lakme Absolute shine line", 350);
		}
		void Maskara() {
			addProduct("Lakme Eyeconic blue mascara", 350);
			addProduct("Lakme Absolute Flutter Secrets voloume Mascara", 550);
			addProduct("Lakme Absolute Flutter Secrets Dramatic Eyes Mascara", 725);
		}
		
	EyeMakeup(){
		EyeShadow();
		EyeLiner();
		Maskara();
	}
};

// Derived class for Face Makeup
class FaceMakeup : public MakeupCategory {
	public:
	    void FaceBlush() {
	        addProduct("Lakme Absolute Illuminating Shimmer Brick", 726);
	        addProduct("Lakme 9to5 Pure Rouge Blusher", 475);
	        addProduct("Lakme 9to5 Flawless Matte Complexion Compact-Melon", 375);
	        addProduct("Lakme 9to5 Flawless Makeup-Mrable", 575);
	        addProduct("Lakme Absolute Face Stylish Blush Duos", 750);
	        addProduct("Lakme Face Sheer Sun Kissed", 340);
	    }
		
		void FaceFoundation() {
			addProduct("Lakme Absolute Moon Kit Highlighter", 726);
			addProduct("Lakme Absolute Sun Kissed Bronzer", 725);
			addProduct("Lakme Absolute illuminating Foundation", 750);
			addProduct("Lakme Absolute Blur Perfect Primer", 650);
			addProduct("Lakme Invisible Finish Foundation", 350);
			addProduct("Lakme Silk Naturelle Daily Foundation Pearl", 350);
			addProduct("Lakme Absolute White Instance Skin Cover Foundation", 508);
		}
		
		void FaceMousse() {
			addProduct("Lakme 9to5 Weightless Mousse Foundation", 575);
			addProduct("Lakme Absolute Mattreal Skin Natural Mousse", 725);
			addProduct("Lakme Jewel Sindhoor", 140);
		}
	
	FaceMakeup(){
		FaceBlush();
		FaceFoundation();
		FaceMousse();
	}
};

// Derived class for Lip Makeup
class LipMakeup : public MakeupCategory{
	public:
		void Lipstick(){
			addProduct("Lakme enrich Lip caryon", 185);
			addProduct("Lakme Enrich Matte Lipstick", 295);
			addProduct("Lakme Absolute Argon Oil Lip Colour", 750);
			addProduct("Lakme Absolute Lip pout-creme", 650);
			addProduct("Lakme Absolute Lip pout-creme", 700);
			addProduct("Lakme absolute illuminating Lip Shinner", 450);
			addProduct("Lakme 9to5 Lakme Lip Colour", 800);
			addProduct("Lakme absolute Gloss Addict-perfect Plum", 800);
			addProduct("Lakme absolute Gloss Addict", 800);
			addProduct("Lakme absolute Gloss Addict-Rustic Red", 800);
			addProduct("Lakme absolute Gloss Addict-Coral Pink", 800);
			addProduct("Lakme absolute Gloss Addict-Fine Wine", 650);
			addProduct("Lakme absolute Lip Pout-Matte", 800);
			addProduct("Lakme absolute Gloss Addict-Berry Crush", 675);
			addProduct("Lakme absolute creme Lipcolour-Flaming Plum", 450);
			addProduct("Lakme absolute Sculpt Studio Hi Definition Matte Lipstick", 750);
			addProduct("Lakme 9to5 crease-less Lip Colour", 250);
		}
		
		void LipWear_Gloss_Balm() {
			addProduct("Lakme 9to5 Lip Liner", 400);
			addProduct("Lakme Absolute Forever Silk Lip Liner", 475);
			addProduct("Lakme Absolute Gloss Stylist-Berry Rose", 700);
			addProduct("Lakme Absolute Gloss Stylist-Wine Shine", 700);
			addProduct("Lakme Absolute Gloss Stylist-Plum Pout", 700);
			addProduct("Lakme Absolute Gloss Stylist-Coral Blush", 700);
			addProduct("Lakme Absolute Gloss Stylist-Red Touch", 700);
			addProduct("Lakme Absolute Gloss Stylist", 700);
			addProduct("Lakme Lip Love Lip Care", 200);
		}
		
	LipMakeup(){
		Lipstick();
		LipWear_Gloss_Balm();
	}
};

// Derived class for nail Makeup
class NailMakeup : public MakeupCategory{
	public:
		NailMakeup() {
			addProduct("Lakme Absolute Gel Stylish", 400);
			addProduct("Lakme 9to5 Long Wea", 220);
			addProduct("Lakme absolute Gel stylist", 400);
			addProduct("Lakme 9to5 Nail Frosties", 220);
			addProduct("Lakme True Wear Colour Crush 58", 160);
			addProduct("Lakme Colour Crush", 160);
			addProduct("Lakme True Wear Colour Crush 55", 160);
			addProduct("Lakme Ultra Nail Enamel Remover", 80);
		}
};

// Derived class for skin Makeup
class SkinMakeup : public MakeupCategory{
	public:
		void SkinBright() {
			addProduct("Lakme Absolute Perfect Radiance Skin Lightning Day cream 15gm", 115);
			addProduct("Lakme Absolute Perfect Radiance Skin Lightning Light Cream", 335);
			addProduct("Lakme Absolute Perfect Radiance Skin Lightning  UV lotion", 299);
			addProduct("Lakme Absolute Perfect Radiance Skin Lightning  Serum", 849);
			addProduct("Lakme Absolute Perfect Radiance Skin Lightning Night Cream", 355);
			addProduct("Lakme Absolute Perfect Radiance Skin Lightning Day Creame 50gm", 280);
			addProduct("Lakme CC creame", 220);
			addProduct("Lakme 9to5 CC Colur Transform Cream", 325);
		}
		
		void Moisturizer(){
			addProduct("Lakme Skin Gloss Lotion Winter cream 50GM", 220);
			addProduct("Lakme Maximum Mostirizer Winter Intense 200ml", 330);
			addProduct("Lakme Maximum Mostirizer Winter Intense 60ml", 299);
			addProduct("Lakme Pitch Milk Mostirizer With SPF 24++ 120ml", 849);
			addProduct("Lakme Maximum Mostirizer Pitch Milk 200ml", 335);
			addProduct("Lakme Maximum Mostirizer Pitch Milk 60ml", 280);
		}
		
		void SunProtect(){
			addProduct("Lakme Sun Expert + UV Lotion SPF 50 PA+++50 ML", 280);
			addProduct("Lakme Sun Fairness + UV Lotion SPF 24 PA++60 ML", 200);
			addProduct("Lakme Sun Fairness + UV Lotion SPF 30 PA++60 ML", 190);
			addProduct("Lakme 9to5 Mattifing Super Sunscreen", 500);
			addProduct("Lakme 9to5 Haydrating Super Sunscreen", 500);
			addProduct("Lakme Sun Fairness + UV Lotion SPF 24 PA++120 ML", 375);
			addProduct("Lakme Sun Expert+ UV Lotion SPF 50 PA++100 ML", 500);
			addProduct("Lakme Sun Fairness + UV Lotion SPF 30 PA++60 ML", 375);
		}
		
		void Cleanser(){
			addProduct("Lakme Blush & Glow Claen Up Face Mask 50 GM", 120);
			addProduct("Lakme Blush & Glow Face Scrub 50 GM", 120);
			addProduct("Lakme Blush & Glow Gel Facewash Pomegranate 100 GM", 185);
			addProduct("Lakme Blush & Glow Gel Facewash Peach 100 GM", 99);
			addProduct("Lakme Blush & Glow Gel Facewash Strawberry 100 GM", 185);
			addProduct("Lakme Blush & Glow Gel Facewash Strawberry 50 GM", 185);
			addProduct("Lakme Blush & Glow Gel Facewash Peach 50 GM", 99);
			addProduct("Lakme Blush & Glow cream Facewash Peach 100 GM", 99);
			addProduct("Lakme Blush & Glow cream Facewash Strawberry 100 GM", 185);
			addProduct("Lakme Blush & Glow cream Facewash Strawberry 50 GM", 99);
		}
		
	SkinMakeup(){
		SkinBright();
		Moisturizer();
		SunProtect();
		Cleanser();
	}
};


// Main Application Class
class LakmeApp {
	private:
		MakeupCategory mk;
	    EyeMakeup eyeMakeup;
	    FaceMakeup faceMakeup;
	    LipMakeup lipMakeup;
	    NailMakeup nailMakeup;
	    SkinMakeup skinMakeup;

	public:
	    void displayMenu() {
	        cout << "\nWelcome to Lakme Shopping App!\n";
	        cout << "1. Eye Makeup\n";
	        cout << "2. Face Makeup\n";
	        cout << "3. Lip Makeup\n";
	        cout << "4. Nail Makeup\n";
	        cout << "5. Skin Makeup\n";
	        cout << "6. View Cart and Checkout\n";
	        cout << "7. Exit\n";
	    }
	    
		void handleChoice() {
	    	int choice;
	        do {
	            displayMenu();
	            cout << "Enter your choice: ";
	            cin >> choice;
	
	            switch (choice) {
	            case 1:
	                handleCategory(eyeMakeup, "Eye Makeup");
	                break;
	            case 2:
	                handleCategory(faceMakeup, "Face Makeup");
	                break;
	            case 3:
	            	handleCategory(lipMakeup, "Lip Makeup");
	            	break;
	            case 4:
					handleCategory(nailMakeup, "Nail Makeup");
					break;
				case 5:
					handleCategory(skinMakeup, "Skin Makeup");
					break;
				case 6:
	                checkout();
	                break;
	            case 7:
	                cout << "Thank you for shopping with us!\n";
	                break;
	            default:
	                cout << "Invalid choice. Please try again.\n";
	            }
	        } while (choice != 7);
	    }
	    
	    void handleCategory(MakeupCategory& category, const string& categoryName) {
	    	
			cout << "\n\n" << categoryName << " Section\n";
	        category.displayProducts();
	        
			cout << "\nEnter the product number to purchase (or 0 to go back): ";
	        int productIndex;
	        cin >> productIndex;
	        
			if (productIndex == 0) return;
	        
			cout << "Enter quantity: ";
	        int quantity;
	        cin >> quantity;
	        
			category.purchaseProduct(productIndex, quantity);
		}
		
	    void checkout() {
	        cout << "\n--- Checkout ---\n";
			int total = 0;

			//Display eye makeup products
			cout << "\nEye Makeup Products:\n";
			total += mk.displayCategoryBill(eyeMakeup);

			//Display face makeup products
			cout << "\nFace Makeup Products:\n";
			total += mk.displayCategoryBill(faceMakeup);

			//Display lip makeup products
			cout << "\nLip Makeup Products:\n";
			total += mk.displayCategoryBill(lipMakeup);

			//Display nail makeup products
			cout << "\nNails makeup Products:\n";
			total += mk.displayCategoryBill(nailMakeup);

			//Display skin makeup products
			cout << "\nSkin Care Products:\n";
			total += mk.displayCategoryBill(skinMakeup);

			//total cost
			cout << "\nGrand Total: " << total << "rs.\n";
	    }
};


int main() {
    LakmeApp app;
	string username, gmail, address;
	int phone_no, pass1, pass2;

	//Login section
	cout << "\n----- LAKME STORE LOGIN -----\n\n";
	cout << "Username : ";
	cin >> username;
	cout << "Create password: ";
	cin >> pass1;
	cout << "conform password: ";
	cin >> pass2;
	
	if (pass1==pass2){
		cout <<"Sign in sussesfully...";
	} else{
		cout << "Wrong Password.\n";
	}

    app.handleChoice();

	//Delivery Details
	cout << "\n----- DELIVERY DETAILS -----\n\n";
	cout << "Name: ";
	cin >> username;
	cout << "Address: ";
	cin >> address;
	cout << "Contact number: ";
	cin >> phone_no;
	
	int ch;
	cout << "1. cash on delivery \n2. Online payment \n";
	cout << "choise: ";
	cin >> ch;
	
	if (ch==1){
		cout << "\nYour order will be delivered within 3-4 working days. Thank you!\n";
	}
	else if(ch==2){
		int num;
		cout << "Enter your UPI number \n";
		cin >> num;
		cout << "\nPayment Successfully....";
		cout << "\nYour order will be delivered within 3-4 working days. Thank you!\n";
	} else{
		cout << "\nInvalid option\n";
	}

    return 0;
}