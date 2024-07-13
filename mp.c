/**********************************************************************************************************
This is to certify that this project is our own work, based on our personal efforts in studying and 
applying the concepts learned. We have constructed the functions and their respective algorithms and 
corresponding code by ourselves. The program was run, tested, and debugged by our own efforts. 
We further certify that  have not copied in part or whole or otherwise plagiarized the work of other 
students and/or persons.
                                                        VILLANUEVA, Keisha Leigh D.M., DLSU ID# 12210021
                                                        WONG, Abigail C.,              DLSU ID# 12210188 
*********************************************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_USERS               100     // maximum number of users in the database
#define MAX_ITEMS_SELLERS       20      // maximum number of items per seller
#define MAX_ITEMS_TRANSACTION   5       // maximum number of items per transaction
#define MAX_ITEMS               2000    // maximum number of items in the database
#define MAX_CART_ITEMS          10      // maximum number of items per user
#define MAX_NAME                21      // maximum number of characters for user/product name
#define MAX_PASSWORD            11      // maximum number of characters for user password
#define MAX_ADDRESS             31      // maximum number of characters for user address
#define MAX_CATEGORY            16      // maximum number of characters for item category 
#define MAX_DESCRIPTION         31      // maximum number of characters for item description

// struct to store user information
typedef struct{
    char name[MAX_NAME];
    int userID;
    char password[MAX_PASSWORD];
    char address[MAX_ADDRESS];
    int contactNum;
    int itemCounter;
} USER;

// struct to store item information
typedef struct{
    int productID;
    char name[MAX_NAME];
    char category[MAX_CATEGORY];
    char description[MAX_DESCRIPTION];
    int productQuantity;
    double unitPrice;
    int sellerID;
} ITEM;

// struct to store date
typedef struct{
    int month; 
    int day;
    int year;
} DATE; 

// struct to store transaction information
typedef struct{
    DATE date;
    ITEM item[MAX_ITEMS_TRANSACTION];
    USER user;
    int buyerID; 
    int sellerID;
    float totalAmount;
} TRANSACTION;

// struct to store cart information
typedef struct{
    ITEM item[MAX_CART_ITEMS];
    TRANSACTION transact;
    int itemCounter;
} CART;

/*
This function displays the main menu of the program and asks the user for user input action to display the choice chosen 
@param *choice contains the user input action
Pre-condition: *choice is an integer value, user inputs 1, 2, 3, 4
*/

void displayMainMenu(int *choice){

    printf("\n");
    printf("            +----------------------------------------------------+\n");
    printf("            |                                                    |\n");
    printf("            |            ADD TO CART NOW WITH CLICKART!          |\n");
    printf("            |                                                    |\n");
    printf("            |            [ 1 ] Register as a New User            |\n");
    printf("            |            [ 2 ] View User Menu                    |\n");
    printf("            |            [ 3 ] View Admin Menu                   |\n");
    printf("            |            [ 4 ] Exit Program                      |\n");
    printf("            |                                                    |\n");
    printf("            +----------------------------------------------------+\n");   
    printf("\n");
    
    printf("                            Enter your Choice: "); 
    scanf(" %d", choice);
}

/*
This function displays the user menu of the program and asks the user for user input action to display the choice chosen 
@param *choice contains the user input action
Pre-condition: *choice is an integer value, user inputs 1, 2, 3
*/

void displayUserMenu(int *choice){
    printf("\n");
    printf("            +----------------------------------------------------+\n");   
    printf("            |                                                    |\n");
    printf("            |                      USER MENU                     |\n");
    printf("            |                                                    |\n"); 
    printf("            |               [ 1 ] View Sell Menu                 |\n");
    printf("            |               [ 2 ] View Buy Menu                  |\n");
    printf("            |               [ 3 ] Exit User Menu                 |\n");
    printf("            |                                                    |\n");
    printf("            +----------------------------------------------------+\n");   
    printf("\n");
    
    printf("                            Enter your Choice: "); 
    scanf(" %d", choice);

}

/*
This function displays the user sell menu of the program and asks the user for user input action to display the choice chosen 
@param *choice contains the user input action
Pre-condition: *choice is an integer value, user inputs 1, 2, 3, 4, 5
*/

void displayUserSellMenu(int *choice){
    printf("\n");
    printf("            +----------------------------------------------------+\n");   
    printf("            |                                                    |\n");
    printf("            |                     SELl MENU                      |\n");
    printf("            |                                                    |\n"); 
    printf("            |            [ 1 ] Add New Item                      |\n");
    printf("            |            [ 2 ] Edit Stock                        |\n");
    printf("            |            [ 3 ] View My Products                  |\n");
    printf("            |            [ 4 ] View My Low Stock Products        |\n");
    printf("            |            [ 5 ] Exit Sell Menu                    |\n");
    printf("            |                                                    |\n");
    printf("            +----------------------------------------------------+\n");   
    printf("\n");

    printf("                            Enter your Choice: "); 
    scanf(" %d", choice);
}

/*
This function displays the submenu of edit stock and asks the user for user input action to display the choice chosen 
@param *choice contains the user input action
Pre-condition: *choice is an integer value, user inputs 1, 2, 3, 4, 5, 6
*/

void displayEditStock(int *choice){
    printf("\n");
    printf("            +----------------------------------------------------+\n");   
    printf("            |                                                    |\n");
    printf("            |                     EDIT STOCK                     |\n");
    printf("            |                                                    |\n"); 
    printf("            |             [ 1 ] Replenish                        |\n");
    printf("            |             [ 2 ] Change Price                     |\n");
    printf("            |             [ 3 ] Change Item Name                 |\n");
    printf("            |             [ 4 ] Change Category                  |\n");
    printf("            |             [ 5 ] Change Description               |\n");
    printf("            |             [ 6 ] Finish Editing                   |\n");
    printf("            |                                                    |\n");
    printf("            +----------------------------------------------------+\n");   
    printf("\n");

    printf("                            Enter your Choice: "); 
    scanf(" %d", choice);
}

/*
This function displays the user buy of the program and asks the user for user input action to display the choice chosen 
@param *choice contains the user input action
Pre-condition: *choice is an integer value, user inputs 1, 2, 3, 4, 5, 6, 7, 8
*/

void displayUserBuyMenu(int *choice){
    printf("\n");
    printf("            +----------------------------------------------------+\n");   
    printf("            |                                                    |\n");
    printf("            |                      BUY MENU                      |\n");
    printf("            |                                                    |\n"); 
    printf("            |    [ 1 ] View All Products                         |\n");
    printf("            |    [ 2 ] Show All Products by a Specific Seller    |\n");
    printf("            |    [ 3 ] Search Products by Category               |\n");
    printf("            |    [ 4 ] Search Products by Name                   |\n");
    printf("            |    [ 5 ] Add to Cart                               |\n");
    printf("            |    [ 6 ] Edit Cart                                 |\n");
    printf("            |    [ 7 ] Check Out Menu                            |\n"); 
    printf("            |    [ 8 ] Exit Buy Menu                             |\n");
    printf("            |                                                    |\n");
    printf("            +----------------------------------------------------+\n");   
    printf("\n");

    printf("                            Enter your Choice: "); 
    scanf(" %d", choice);
}

/*
This function displays the submenu of edit cart and asks the user for user input action to display the choice chosen 
@param *choice contains the user input action
Pre-condition: *choice is an integer value, user inputs 1, 2, 3, 4
*/

void displayEditCart(int *choice){
    printf("\n");
    printf("            +----------------------------------------------------+\n");   
    printf("            |                                                    |\n");
    printf("            |                      EDIT CART                     |\n");
    printf("            |                                                    |\n"); 
    printf("            |        [ 1 ] Remove all items from Seller          |\n");
    printf("            |        [ 2 ] Remove Specific Item                  |\n");
    printf("            |        [ 3 ] Edit Quantity                         |\n");
    printf("            |        [ 4 ] Finish Edit Cart                      |\n");
    printf("            |                                                    |\n");
    printf("            +----------------------------------------------------+\n");   
    printf("\n");

    printf("                            Enter your Choice: "); 
    scanf(" %d", choice);
}

/*
This function displays the submenu of check out menu and asks the user for user input action to display the choice chosen 
@param *choice contains the user input action
Pre-condition: *choice is an integer value, user inputs 1, 2, 3, 4
*/

void displayCheckOutMenu(int *choice){
    printf("\n");
    printf("            +----------------------------------------------------+\n");   
    printf("            |                                                    |\n");
    printf("            |                 CHECK OUT MENU                     |\n");
    printf("            |                                                    |\n"); 
    printf("            |        [ 1 ] Buy All                               |\n");
    printf("            |        [ 2 ] Buy from a Specific Seller            |\n");
    printf("            |        [ 3 ] Buy a Specific Item                   |\n");
    printf("            |        [ 4 ] Exit Check Out                        |\n");
    printf("            |                                                    |\n");
    printf("            +----------------------------------------------------+\n");   
    printf("\n");

    printf("                            Enter your Choice: "); 
    scanf(" %d", choice);
}

/*
This function displays the admin menu of the program and asks the user for user input action to display the choice chosen 
@param *choice contains the user input action
Pre-condition: *choice is an value, user inputs 1, 2, 3, 4, 5, 6
*/

void displayAdminMenu(int *choice){
    printf("\n");
    printf("            +----------------------------------------------------+\n");   
    printf("            |                                                    |\n");
    printf("            |                     ADMIN MENU                     |\n");
    printf("            |                                                    |\n");
    printf("            |     [ 1 ] Show All Users                           |\n");
    printf("            |     [ 2 ] Show All Sellers                         |\n");
    printf("            |     [ 3 ] Show Total Sales in Given Duration       |\n");
    printf("            |     [ 4 ] Show Seller Sales                        |\n");
    printf("            |     [ 5 ] Show Shopaholics                         |\n");
    printf("            |     [ 6 ] Back to Main Menu                        |\n");
    printf("            |                                                    |\n");
    printf("            +----------------------------------------------------+\n");   
    printf("\n");

    printf("                            Enter your Choice: "); 
    scanf(" %d", choice);
}

/*
This function reads the users txt file 
@param users is an array of struct 'USERS' that stores all the users currently registered in the database 
@param *num_users users currently store the number of users registered
Pre-condition: the users.txt file exists and contains valid user data in the correct format
*/

void readUsersFile(int *num_users, USER users[MAX_USERS]){
    FILE *file;
    int i = 0;

    // read mode
    file = fopen("Users.txt", "r");
        while(fscanf(file, "%d", &users[i].userID) != EOF){
            fscanf(file, " %11s", users[i].password);
			fscanf(file, "%20[^\n]", users[i].name);
			fscanf(file, "%30[^\n]", users[i].address);
			fscanf(file, "%d", &users[i].contactNum);
            fscanf(file, "%*[^\n]%*c]");	            
            *num_users +=1;
			i++;
        }
   fclose(file);
}

/*
This function saves the data of users in the users txt file 
@param  =users is an array of struct 'USERS' that stores all the users currently registered in the database 
@param num_users users currently store the number of users registered
Pre-condition:  users array contains valid user data and the num_users parameter is the number of users currently stored in the array. 
                Furthermmore, the file "users.txt" is writable, and the program have the permission to create and modify files in the directory 
                where the file is located
*/

void saveUsersDataFiles(int num_users, USER users[]){
    int i;
    
    // write mode
    FILE *user_file = fopen("Users.txt", "w");
    for (i = 0; i < num_users; i++) {
        fprintf(user_file, "%d %s\n%s\n%s\n%d\n\n", users[i].userID, users[i].password, users[i].name, users[i].address, users[i].contactNum);
    }
    fclose(user_file);

}

/*
This function reads the items txt file 
@param products is an array of struct 'ITEMS' that stores all the items currently registered in the database 
@param num_items items currently store the number of items registered
Pre-condition: the items.txt file exists and contains valid user data in the correct format
*/

void readItemsFile(int *num_items, ITEM products[MAX_ITEMS]){
    FILE *file;
    int i = 0;

    // read mode
    file = fopen("Items.txt", "r");
        while(fscanf(file, "%d", &products[i].productID) != EOF){
            fscanf(file, "%d", &products[i].sellerID);
            fscanf(file, "%20[^\n]", products[i].name);
			fscanf(file, "%15[^\n]", products[i].category);
			fscanf(file, "%30[^\n]", products[i].description);
			fscanf(file, "%d", &products[i].productQuantity);
            fscanf(file, "%lf", &products[i].unitPrice);
		    fscanf(file, "%*[^\n]%*c]");	
            *num_items +=1;
			i++;
        }
   fclose(file);
}

/*
This function saves the data of items in the items txt file 
@param products is an array of struct 'ITEMS' that stores all the items currently registered in the database 
@param num_items items currently store the number of items registered
Pre-condition:  products array contains valid user data and the num_items parameter is the number of items currently stored in the array. 
                Furthermmore, the file "items.txt" is writable, and the program have the permission to create and modify files in the directory 
                where the file is located
*/

void saveItemsDataFiles(int num_items, ITEM products[]){
    int i;
    
    // write mode
    FILE *item_file = fopen("Items.txt", "w");
    for (i = 0; i < num_items; i++) {
        fprintf(item_file, "%d %d\n%s\n%s\n%s\n%d %f\n\n", products[i].productID, products[i].sellerID, products[i].name, products[i].category, products[i].description, products[i].productQuantity, products[i].unitPrice);
    }
    fclose(item_file);

}

/*
This function checks the user numeric ID if its unique  
@param userID is the numeric user id of the user that needs to be checked
@param users is an array of struct 'USERS' that stores all the users currently registered in the database 
@param num_users users currently store the number of users registered in the database
Pre-condition:  userID parameter is a positive integer and is unique, and the users array contains valid user data, 
                and the num_users parameter is the number of users registered in the database
*/

int isNumIDValid(int userID, USER users[], int num_users){

    if (userID <= 0) {
        printf("Invalid User ID. Please enter a positive integer. \n");
        return 0;
    }
    
    int i;

    for (i = 0; i < num_users; i++) {
        if (users[i].userID == userID) {
            printf("User ID already exists. Please enter a unique User ID. \n");
            return 0;
        }
    }

    printf("\nThe User ID is valid. \n");
    return 1;
}

/*
This function checks the user registration if it's valid or not
@param *str is a pointer to a string containing the user input
@param max_len contains the maximum length allowed for the input string
Pre-condition:  str is a valid pointer to a null-terminated string, and max_len is a positive integer representing the 
                maximum length allowed for the input string
*/

int isUserValid(char *str, int max_len){
    int len = strlen(str); // strlen function is to determine the length of the input string
    if (len > max_len){
        printf("\nUser input error. Please try again. \n");
        return 0; // user input is greater than the maximum length
    }

    return 1; // user input is valid
}

/*
This function asks the user for information input respectively
@param users[] an array of USER struct and represents the list of registered users
@param *num_users a pointer to an integer and represents the number of users registered 
Pre-condition:  users array should have enough space to store a new user information, and the num_users pointer should point 
                to the number of users currently registered in the database
*/

void userRegister(USER users[], int *num_users){ 
    USER newUser;

    do { 
        printf("\nEnter your User ID: ");
        scanf(" %d", &newUser.userID);
    } while (isNumIDValid(newUser.userID, users, *num_users) !=1);

    do{
        printf("\nEnter your Password: ");
        scanf(" %[^\n]", newUser.password);
    } while (!isUserValid(newUser.password, 11));     
    
    do{
        printf("\nEnter your Name: ");
        scanf(" %[^\n]",newUser.name);
    } while (!isUserValid(newUser.name, 21));  

    do{
        printf("\nEnter your Address: ");
        scanf(" %[^\n]", newUser.address);
    } while (!isUserValid(newUser.address, 31)); 
    
    printf("\nEnter your Contact Number: ");
    scanf(" %d", &newUser.contactNum);
   
    users[*num_users] = newUser;
    *num_users += 1;

    printf("\nRegistration Successful!\n");
}   

/*
This function asks the user for information input respecctively and checks if successful login
@param users[] an array of USER struct and represents the list of registered users
@param *num_users a pointer to an integer and represents the number of registered 
@param *sellerID a pointer to an integer and represents the sellerID of the user
Pre-condition:  users array should be a valid array of USER structs with at most MAX_USERS number of elements
                num_users should be a valid pointer to an integer representing the number of registered users, with a value greater than or equal to 0
                sellerID should be a valid pointer to an integer representing the ID of the user who is currently logged in
*/

int userMenu(int num_users, USER users[MAX_USERS], int *sellerID){
    int i;
    USER newUser;

    printf("\nEnter your ID: ");
    scanf("%d", &newUser.userID);

    printf("\nEnter your password: ");
    scanf("%s", newUser.password);

    for(i = 0; i < num_users; i++){
        if(newUser.userID == users[i].userID && strcmp(users[i].password, newUser.password) == 0){
            printf("\nLogin successful!\n");
             *sellerID = users[i].userID;
            return 1;
        }
    }
    printf("\nInvalid userID or password. Please try again.\n\n");
    return -1;
}

/*
This function searches the index of the user with the given userID 
@param users[] is an array of USER struct and represents the list of registered users
@param *num_users is a pointer to an integer and represents the number of registered 
@param userID contains the userID of the user to be search for
Pre-condition:  users array should be a valid array of USER structs
                num_users pointer should point to an integer that represents the number of registered users
                userID integer parameter should be a valid user ID to search for
*/

int findUserID(USER users[], int num_users, int userID){
    int i;

    for(i = 0; i < num_users; i++){ 
        if(users[i].userID == userID){
            return i;
        }
    }
    return -1; //user not found
}

/*
This function checks the product numeric ID if it's unique
@param productID is the numeric product ID of the item that needs to be checked
@param products[] is an array of struct 'ITEM' that stores all the products currently in the database
@param itemCount are the items currently stored in the sellers array
Pre-condition:  ITEM struct is defined and contains a member variable named 'productID'
                productID parameter is a non-negative integer
                ITEM array products contains valid ITEM structs
                itemCount contains the number of items stored in the products array
*/

int isProductIDValid(int productID, ITEM products[], int itemCount) {
    if (productID <= 0) {
        printf("Invalid product ID. Please enter a positive integer. \n");
        return 0;
    }

    int i;

    for (i = 0; i < itemCount; i++) {
        if (products[i].productID == productID) {
            printf("Product ID already exists. Please enter a unique Product ID. \n");
            return productID;
        }
    }

    printf("\nThe Product ID is valid. \n");
    return 1;
}

/*
This function adds a new item to sell from the user who is a seller
@param users[] is an array of USER struct and represents the list of registered users
@param products[] is an array of ITEM struct and represents the list of items for sale
@param *itemCount is a pointer to an integer and stores the current count of items in the 'products' array
@param userID contains the userID of the user
@param sellerID contains the sellerID of the user who is a seller also
@param *num_users is a pointer to an integer and represents the number of registered 
Pre-condition:  users array is not empty and contains valid user data
                products array is not full (i.e. there is space to add a new item)
                itemCount pointer is not null and points to a valid integer variable that stores the current count of items in the products array
                userID and sellerID parameters are valid and correspond to registered users and sellers in the users and products array
                num_users pointer is not null and points to a valid integer variable that stores the current number of registered users
                isProductIDValid function is implemented and returns the expected values (i.e. 1 for a valid product ID, 0 or a non-unique ID for an invalid one)
                isUserValid function is implemented and returns the expected values (i.e. true for valid user input, false otherwise)
*/

void addNewItem(USER users[], ITEM products[], int *itemCount, int userID, int sellerID, int *num_users){
    int productID;
    int userIndex = findUserID (users, *num_users, userID);
    
    if(users[userIndex].itemCounter >= 20) { 
        printf("\nSeller has reached the item limit. Please try again.\n");
        return;
    } 

    ITEM newProduct;

    do {
        printf("\nEnter Product ID: ");
        scanf("%d", &productID);
    } while (isProductIDValid(productID, products, *itemCount) != 1) ;

    do{
        printf("\nEnter Item Name: ");
        scanf(" %[^\n]", newProduct.name);
    } while (!isUserValid(newProduct.name, 21));
    
    do{
        printf("\nEnter Item Category: ");
        scanf(" %[^\n]", newProduct.category);
    } while (!isUserValid(newProduct.category, 16));
    
    do{
        printf("\nEnter Item Description: ");
        scanf(" %[^\n]", newProduct.description);
    } while (!isUserValid(newProduct.description, 31));

    printf("\nEnter Item Quantity: ");
    scanf("%d", &newProduct.productQuantity);
    
    printf("\nEnter Item Price: ");
    scanf("%lf", &newProduct.unitPrice);

    newProduct.productID = productID;
    newProduct.sellerID = sellerID;    

    products[*itemCount] = newProduct;
    *itemCount += 1;

    users[userIndex].itemCounter++;
    
    printf("\nItem added successfully.\n");
}
    
/*
This function edits the stock of the seller
@param products[] is an array of ITEM struct and represents the list of items for sale
@param sellerID contains the sellerID of the user who is a seller also
@param *itemCount is a pointer to an integer and stores the current count of items in the 'products' array
Pre-condition:  products array is not full (i.e. there is space to add a new item)
                sellerID parameter is valid and correspond to registered sellers in the products array
                itemCount pointer is not null and points to a valid integer variable that stores the current count of items in the products array
*/

void editStock(ITEM products[], int sellerID, int *itemCount){

    printf("\n");
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("|                                        MY PRODUCTS                                   |\n");
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("|%-10s| %-25.20s| %-20.16s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "UNIT PRICE", "QUANTITY");
    printf("+--------------------------------------------------------------------------------------+\n");

    // print each product row in the table
    for (int i = 0; i < *itemCount; i++) {
        if (products[i].sellerID == sellerID){
            printf("|%10d| %-25.20s| %-20.16s| ₱%12.2f| %10d|\n", 
                                                products[i].productID, 
                                                products[i].name, 
                                                products[i].category, 
                                                products[i].unitPrice, 
                                                products[i].productQuantity);
            printf("+--------------------------------------------------------------------------------------+\n");
        }
    }
    
    int productID; 
    printf("\nEnter product ID to edit: ");
    scanf("%d", &productID);

    // find item with matching productID
    ITEM *productToEdit = NULL;
    int j;
    for (j = 0; j < *itemCount; j++){
        if (products[j].sellerID == sellerID && products[j].productID == productID){
            productToEdit = &products[j];
        }
    }

    if (productToEdit == NULL) {
        printf("\nInvalid productID. Please try again.\n");
        return;
    }

    // edit submenu loop
    int choice = 0;
    int quantityToAdd;
    char newItemName[MAX_NAME];
    char newCategory[MAX_CATEGORY];
    char newDescription[MAX_DESCRIPTION];
    double newPrice;
   
    while (choice != 6) {
        displayEditStock(&choice);

        switch (choice){
        
        case 1: // replenish Item
            printf("\nEnter the quantity to Add: ");
            scanf("%d", &quantityToAdd);
            productToEdit->productQuantity += quantityToAdd;
            printf("\nItem Stock replenished successfully!\nUpdated Quantity: %d\n", productToEdit->productQuantity);
            break;

        case 2: // edit price
            printf("\nEnter New Item Price: ");
            scanf("%lf", &newPrice);
            productToEdit->unitPrice = newPrice;
            printf("\nItem Price has been updated successfully!\n");
            break;

       case 3: // edit Name
            printf("\nEnter New Item Name: ");
            scanf(" %[^\n]", newItemName);
            strcpy(productToEdit->name, newItemName); 
            printf("\nItem name has been updated successfully!\n");
            break;

        case 4: // edit Category
            printf("\nEnter New Item Category: ");
            scanf(" %[^\n]", newCategory);
            strcpy(productToEdit->category, newCategory);
            printf("\nItem category has been updated successfully!\n");
            break;

        case 5: // edit Description
            printf("\nEnter New Item Description: ");
            scanf(" %[^\n]", newDescription);
            strcpy(productToEdit->description, newDescription);
            printf("\nItem Description has been updated successfully!\n");
            break;

        case 6: // finish Editing
            printf("\nAll changes updated!\n");
            break;
        
        default:
            printf("\nInvalid input. Please input again\n");
            break;
        }
    }
}

/*
This function shows the list of products of seller and sorted in increasing order based on the productID
@param ITEM *products is a pointer to an array of ITEM struct that represents the list of products
@param sellerID contains the sellerID of the user who is a seller also
@param *itemCount is a pointer to an integer and stores the current count of items in the 'products' array
Pre-condition:  products parameter is a valid pointer to an array of ITEM struct that contains at least *itemCount number of elements
                sellerID parameter is a valid integer that represents the ID of the seller whose products are being displayed
                itemCount parameter is a valid pointer to an integer that stores the current number of items in the products array
*/

void displayMyProducts(ITEM* products, int sellerID, int *itemCount) {

    int i, j;

    // sort the products array by productID in increasing order
    for (i = 0; i < *itemCount - 1; i++){
        for (j = i + 1; j < *itemCount; j++){
            if (products[i].productID > products[j].productID){
                // swap the products
                ITEM temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    
    printf("\n");
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("|                                        MY PRODUCTS                                   |\n");
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("|%-10s| %-25.20s| %-20.16s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "UNIT PRICE", "QUANTITY");
    printf("+--------------------------------------------------------------------------------------+\n");

    // print each product row in the table
    for (i = 0; i < *itemCount; i++) {
        if (products[i].sellerID == sellerID){
            printf("|%10d| %-25.20s| %-20.16s| ₱%12.2f| %10d|\n", 
                                                products[i].productID, 
                                                products[i].name, 
                                                products[i].category, 
                                                products[i].unitPrice, 
                                                products[i].productQuantity);        
            printf("+--------------------------------------------------------------------------------------+\n");
        }
    }
}

/*
This function displays the product whose quantity is below 5
@param products[] is an array of ITEM struct and represents the list of items for sale
@param itemCount is an integer and stores the current count of items in the 'products' array'
@param sellerID contains the sellerID of the user who is a seller also
Pre-condition:  products array is not full (i.e. there is space to add a new item)
                itemCount is a valid integer variable that stores the current count of items in the products array 
                sellerID parameter is valid and correspond to registered sellers in the products array
*/

void displayLowStockProducts(ITEM products[], int itemCount, int sellerID){
    int currentProduct = 0;
    char input; 

    // loop through each product in the arrray
    while (currentProduct < itemCount){
        if (products[currentProduct].sellerID == sellerID){
        // if the quantity is less than 5, print the product data
            if (products[currentProduct].productQuantity < 5) {
                printf("\n");
                printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
                printf("|                                                       LOW STOCK PRODUCTS                                                  |\n");
                printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
                printf("|%-10s| %-25.20s| %-20.16s| %-35.30s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "DESCRIPTION", "UNIT PRICE", "QUANTITY");
                printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
                printf("|%10d| %-25.20s| %-20.16s| %-35.30s| ₱%12.2f| %10d|\n",
                                            products[currentProduct].productID,
                                            products[currentProduct].name,
                                            products[currentProduct].category,
                                            products[currentProduct].description,
                                            products[currentProduct].unitPrice,
                                            products[currentProduct].productQuantity);
                printf("+---------------------------------------------------------------------------------------------------------------------------+\n");

            // prompt the user to view the next product or exit
            int valid_input = 0;
            while (!valid_input) {
                printf("\nPress N to view the next seller's products, or X to exit: ");
                scanf(" %c", &input);
                if (input == 'N' || input == 'n' || input == 'X' || input == 'x') {
                    valid_input = 1; 
                } else {
                    printf("\nInvalid input. Please enter N or X.\n");
                }
            }
            if (input == 'X' || input == 'x') {
                return;  // exit the function if the user inputs X
            }
            } 
        }

       // move on to the next product
       currentProduct++;
    }
    
   // if we get here, there are no more low quantity products to show
   printf("\nThere are no low quantity products to display.\n");
}

/*
This function displays all items from 1 seller at a time, sorted in increasing order based on seller ID
@param products[] is an array of ITEM struct and represents the list of items for sale
@param itemCount is an integer and stores the current count of items in the 'products' array'
@param sellerID contains the sellerID of the user who is a seller also
Pre-condition:  products array is not full (i.e. there is space to add a new item)
                itemCount is a valid integer variable that stores the current count of items in the products array 
                sellerID parameter is valid and correspond to registered sellers in the products array

*/

void viewAllProducts(ITEM products[], int itemCount, int sellerID) {
    int i, j;
    int currentSeller = -1;  // set initial value to an impossible seller ID
    char input;
    
    // sort the products array by seller ID in increasing order
    for (i = 0; i < itemCount-1; i++) {
        for (j = i+1; j < itemCount; j++) {
            if (products[i].sellerID > products[j].sellerID) {
                ITEM temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    
    // loop through the sorted products array and display each seller's products
    for (i = 0; i < itemCount; i++) {
        // if this product has a different seller ID than the previous one, display the new seller ID
        if (products[i].sellerID != currentSeller) {
            currentSeller = products[i].sellerID;
            printf("+--------------------------------------------------------------------------------------+\n");
            printf("|                          ALL PRODUCTS OF SELLER ID %-10d                        |\n", currentSeller);
            printf("+--------------------------------------------------------------------------------------+\n");
            printf("|%-10s| %-25.20s| %-20.16s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "UNIT PRICE", "QUANTITY");
            printf("+--------------------------------------------------------------------------------------+\n");
        }
        
        // display the current product
        printf("|%10d| %-25.20s| %-20.16s| ₱%12.2f| %10d|\n",
                                        products[i].productID,
                                        products[i].name,
                                        products[i].category,
                                        products[i].unitPrice,
                                        products[i].productQuantity);
        printf("+--------------------------------------------------------------------------------------+\n");
        
        // if this is the last product or the next product has a different seller ID, ask the user if they want to view the next seller's products
        if (i == itemCount-1 || products[i+1].sellerID != currentSeller) {
            int valid_input = 0;
            while (!valid_input) {
                printf("\nPress N to view the next seller's products, or X to exit: ");
                scanf(" %c", &input);
                if (input == 'N' || input == 'n' || input == 'X' || input == 'x') {
                    valid_input = 1; 
                } else {
                    printf("\nInvalid input. Please enter N or X.\n");
                }
            }
            if (input == 'X' || input == 'x') {
                return;  // exit the function if the user inputs X
            }
            printf("\n");
        }
    }
   
    // if we get here, there are no more products to show for this seller
   printf("There are no more products to show for this seller.\n");
}
/*
This function checks if the sellerID is valid 
@param sellerID contains the sellerID of the user who is a seller also
@param products[] is an array of ITEM struct and represents the list of item information
@param *itemCount is a pointer to an integer and represents the number of items
Pre-condition: 
*/

int isSellerIDValid (int sellerID, ITEM products[], int itemCount){
    if (sellerID <= 0) {
        printf("\nInvalid seller ID. Please enter a positive integer.\n");
        return 0;
    }
    int i; 

    for(i = 0; i < itemCount; i++){
        if (products[i].sellerID == sellerID) {
            printf("\nSeller ID has been found.\n");
            return 1;
        }
    }
    
    printf("\nSeller with ID %d does not exist. Please try again.\n", sellerID);
    return 0;
}

/*
This function displays the seller's ID and their product catalog
@param sellerID contains the sellerID of the user who is a seller also
@param itemCount is an integer and stores the current count of items in the products array
@param products[] is an array of ITEM struct and represents the list of items for sale
Pre-condition: the user is asked to specify the seller’s ID they want to view in the program
*/

void searchProductSpecificSeller(int sellerID, int itemCount, ITEM products[]){
   int i, j, inputSellerID;

    do{
        printf("\nEnter Seller ID: ");
        scanf("%d", &inputSellerID);
    } while (isSellerIDValid(inputSellerID, products, itemCount) == 0);

    sellerID = inputSellerID;
   
    // sort the products array by productID in increasing order
    for (i = 0; i < itemCount - 1; i++){
        for (j = i + 1; j < itemCount; j++){
            if (products[i].productID > products[j].productID){
                // swap the products
                ITEM temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    
    printf("\n");
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("|                          PRODUCTS OF SELLER ID %-10d                            |\n", sellerID);
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("|%-10s| %-25.20s| %-20.16s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "UNIT PRICE", "QUANTITY");
    printf("+--------------------------------------------------------------------------------------+\n");

    // print each product row in the table
    for (i = 0; i < itemCount; i++) {
        if (products[i].sellerID == sellerID){
            printf("|%10d| %-25.20s| %-20.16s| ₱%12.2f| %10d|\n", 
                                                products[i].productID, 
                                                products[i].name, 
                                                products[i].category, 
                                                products[i].unitPrice, 
                                                products[i].productQuantity);        
            printf("+--------------------------------------------------------------------------------------+\n");
        }
    }
} 

/*
The function finds products that match the category entered by the user
@param itemCount is an integer and stores the current count of items in the products array
@param products[] is an array of ITEM struct and represents the list of items for sale
Pre-condition: the user is asked to specify the category they want to view in the program
*/

void searchProductCategory(int itemCount, ITEM products[]){
    int currentProduct = 0;
    char input;
    char category[MAX_CATEGORY];

    printf("\nEnter the category you want to see: ");
    scanf("%s", category);
    printf("\n");

    // Loop through each product in the array
    while (currentProduct < itemCount){

        // Check if the category of the current product matches the user input
        if (strcmp(products[currentProduct].category, category) == 0){

            // Print the product details
            printf("\n");
            printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
            printf("|                                                SHOW PRODUCTS BY CATEGORY                                                  |\n");
            printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
            printf("|%-10s| %-25.20s| %-20.16s| %-35.30s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "DESCRIPTION", "UNIT PRICE", "QUANTITY");
            printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
            printf("|%10d| %-25.20s| %-20.16s| %-35.30s| ₱%12.2f| %10d|\n",
                                    products[currentProduct].productID,
                                    products[currentProduct].name,
                                    products[currentProduct].category,
                                    products[currentProduct].description,
                                    products[currentProduct].unitPrice,
                                    products[currentProduct].productQuantity);
            printf("+---------------------------------------------------------------------------------------------------------------------------+\n");

            // Prompt the user to view the next product or exit
            printf("\nPress N to view the next product, or X to exit: ");
            scanf(" %c", &input);

            // If the user enters X, exit the function
            if (input == 'X' || input == 'x') {
                return;
            }
        }

        // Move on to the next product
        currentProduct++;
    }

    // If no product matches the user input category, print an error message
    printf("\nThere are no products to display for this category: %s\n", category);
}



/*
This function finds products that match the keywords entered by the user 
@param products[] is an array of ITEM struct and represents the list of items for sale
@param itemCount is an integer and stores the current count of items in the products array
Pre-condition: the user is asked to specify the keywords they want to view in the program
*/

void searchProductName(ITEM products[], int itemCount){
    int i;
    int found_match = 0;
    int current_index = 0;
    int index[MAX_ITEMS]; // array to store indices of matching products
    char keyword[30];
    char input;
    
    printf("\nEnter keyword to product you want to see: ");
    scanf(" %[^\n]", keyword);
   
   for (i = 0; i < itemCount; i++) {
       if (strstr(products[i].name, keyword) != NULL) {
           index[found_match] = i;
           found_match++;
       }
   }
   
   if (found_match == 0) {
       printf("\nNo products found matching '%s'\n", keyword);
       return;
   }

   while (current_index < found_match) {
        i = index[current_index];
        printf("\n");
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                    SHOW PRODUCTS BY NAME                                                  |\n");
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|%-10s| %-25.20s| %-20.16s| %-35.30s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "DESCRIPTION", "UNIT PRICE", "QUANTITY");
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|%10d| %-25.20s| %-20.16s| %-35.30s| ₱%12.2f| %10d|\n",
                                            products[i].productID,
                                            products[i].name,
                                            products[i].category,
                                            products[i].description,
                                            products[i].unitPrice,
                                            products[i].productQuantity);
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        
        if (current_index == found_match - 1) {
            printf("\nNo further products are available for display based on the keyword\n");
            return;
        }
       
       printf("\nPress N to view the next product, or X to exit: ");
       scanf(" %c", &input);
       
       if (input == 'N' || input == 'n') {
           current_index++;
       } else if (input == 'X' || input == 'x') {
           return;
       } else {
           printf("\nInvalid choice. Try again.\n");
       }

   }
}

/*
This function allows users or buyers to add in their cart 
@param users[] is an array of USER struct and represents the list of registered users
@param *products is a pointer to an array of ITEM struct that represents the list of products
@param *cart is a pointer to an array of CART struct that represents the cart items
@param itemCount is an integer and stores the current count of items in the products array
@param *cartCount is a pointer and an integer and stores the current count of items in the cart array
@param sellerID contains the sellerID of the user who is a seller also
Pre-condition: the user or buyer has not reached their maximum cart item limit
*/

int addtoCart(USER users[], ITEM *products, CART *cart, int itemCount, int *cartCount, int sellerID){
    int productID, quantity, i, found = 0, productIndex = -1;
    
    if (*cartCount >= MAX_CART_ITEMS) {
        printf("\nYour cart is full. Please proceed to Edit Cart or Check Out first before adding more items.\n");
        return 0;
    }

    printf("\nEnter the product ID you want to buy: ");
    scanf("%d", &productID);

    // check if product ID exists
    for (i = 0; i < itemCount; i++) {
        if (products[i].productID == productID) {
            found = 1;
            productIndex = i;
        }
    }

    if (!found) {
        printf("\nProduct not found. Please enter a valid product ID.\n");
        return 0;
    }

    // check if user is trying to buy their own product
    if (products[productIndex].sellerID == sellerID) {
        printf("\nYou cannot buy your own product.\n");
        return 0;
    }

    printf("\nEnter the quantity you want to buy: ");
    scanf("%d", &quantity);

    // check if quantity is available
    if (quantity > products[productIndex].productQuantity) {
        printf("\nQuantity not available. Please enter a smaller quantity.\n");
        return 0;
    }

    // add item to cart
    CART newItem;
    newItem.item[0] = products[productIndex];
    newItem.item[0].productQuantity = quantity;
    newItem.transact.buyerID = users->userID;
    newItem.transact.sellerID = products[productIndex].sellerID;
    newItem.transact.totalAmount = quantity * products[productIndex].unitPrice;

    cart[*cartCount] = newItem;
    (*cartCount)++;
    users->itemCounter++;

    printf("\nItem added to cart successfully.\n");
    return 1;
}

/*
This function shows the current cart of the user or buyer
@param *cart is a pointer to an array of CART struct that represents the cart items
@param *cartCount is a pointer and an integer and stores the current count of items in the cart array
Pre-condition: the user or buyer has added an item to their cart
*/

void displayCart(CART *cart, int *cartCount){
    int i, j;

    printf("\n");
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("|                                      CART ITEMS                                      |\n");
    printf("+--------------------------------------------------------------------------------------+\n");
    printf("|%-10s| %-25.20s| %-20.16s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "UNIT PRICE", "QUANTITY");
    printf("+--------------------------------------------------------------------------------------+\n");
    
    // sort cart by product ID in increasing order
    for (i = 0; i < *cartCount - 1; i++) {
        for (j = i + 1; j < *cartCount; j++) {
            if (cart[i].item[0].productID > cart[j].item[0].productID) {
                CART temp = cart[i];
                cart[i] = cart[j];
                cart[j] = temp;
            }
            // make the sort stable by comparing the item index as a secondary sort key
            else if (cart[i].item[0].productID == cart[j].item[0].productID && cart[i].item[0].sellerID > cart[j].item[0].sellerID) {
                CART temp = cart[i];
                cart[i] = cart[j];
                cart[j] = temp;
            }
        }
    }

    // display cart
    for(i = 0; i < *cartCount; i++){
        CART transaction = cart[i];
            printf("|%10d| %-25.20s| %-20.16s| ₱%12.2f| %10d|\n", 
                                                transaction.item[0].productID, 
                                                transaction.item[0].name, 
                                                transaction.item[0].category, 
                                                transaction.item[0].unitPrice, 
                                                transaction.item[0].productQuantity);         
            printf("+--------------------------------------------------------------------------------------+\n"); 
        }
    }


/*
This function is designed to display the buyer's existing cart and facilitate updates to the items in the cart
@param *users is a pointer to an array of USER struct that represents the users in the database
@param products[] is an array of ITEM struct and represents the list of items for sale
@param *cart is a pointer to an array of CART struct that represents the cart items
@param *cartCount is a pointer and an integer and stores the current count of items in the cart array
Pre-condition: there must be cart items in the user's or buyer's cart 
*/

void editCart(USER *users, ITEM products[], CART *cart, int *cartCount){
    int i, j;
    int choice = 0;
    int sellerID = 0, productID = 0, newQuantity = 0;

    displayCart(cart, cartCount);

    while(choice !=4){
        displayEditCart(&choice);

        switch(choice){
            case 1: // Remove all items from Seller
                printf("\nEnter Seller ID to remove all items from a seller: ");
                scanf(" %d", &sellerID);

                for (i = 0; i < *cartCount; i++) {
                    CART transaction = cart[i];
                    if (transaction.transact.buyerID == users->userID && transaction.transact.sellerID == sellerID) {
                        // shift remaining items in cart down by 1
                        for (j = i; j < *cartCount - 1; j++) {
                            cart[j] = cart[j + 1];
                        }
                        (*cartCount)--;
                        i--;
                    }
                }
                printf("\nAll items from seller %d have been removed from your cart\n", sellerID);
                break;

            case 2: // Remove Specific Item
                printf("\nEnter product ID to remove: ");
                scanf(" %d", &productID);

                int removed = 0;
                for (i = 0; i < *cartCount; i++) {
                    CART transaction = cart[i];
                    if (transaction.transact.buyerID == users->userID && transaction.item[0].productID == productID) {
                        // shift remaining items in cart down by 1
                        for (j = i; j < *cartCount - 1; j++) {
                            cart[j] = cart[j + 1];
                        }
                        (*cartCount)--;
                        printf("\nItem with product ID %d has been removed from your cart.\n", productID);
                        removed = 1;
                    }
                }
                if (!removed) {
                    printf("\nProduct not found in cart. Please enter a valid product ID.\n");
                }
                break;

            case 3: // Edit Quantity
                printf("\nEnter product ID to edit quantity: ");
                scanf("%d", &productID);

                // check if product ID exists in cart
                int found = 0;
                for (i = 0; i < *cartCount; i++) {
                    if (cart[i].item[0].productID == productID) {
                        found = 1;
                    }
                }

                if (!found) {
                    printf("\nProduct not found in cart. Please enter a valid product ID.\n");
                    return;
                }

                for (i = 0; i < *cartCount; i++) {
                    CART transaction = cart[i];
                    
                    if (transaction.transact.buyerID == users->userID && transaction.item[0].productID == productID) {
                        // prompt user for new quantity
                        printf("\nEnter new quantity: ");
                        scanf("%d", &newQuantity);
                    
                        // check if new quantity is available
                        if (transaction.item[0].productQuantity > newQuantity) {
                            printf("\nQuantity not available. Please enter a smaller quantity.\n");
                            return;
                        }

                        transaction.item[0].productQuantity = newQuantity;
                        cart[i] = transaction;
                        printf("\nQuantity of item with product ID %d has been updated to %d.\n", productID, newQuantity);
                    }   
                }
                break;
                
                case 4: // Finish Edit Cart
                    break;

                default:
                    printf("\nInvalid input. Please input again\n");
                    break;
        }
               
                
                
    }
}            

/*
This function checks if the date is valid
@param day an integer representing the day of the date to be checked
@param month an integer representing the month of the date to be checked
@param year an integer representing the year of the date to be checked
Pre-condition:  input parameters day, month, and year should be valid integers and within a 
                reasonable range of values for a date
*/

int isDateValid(int day, int month, int year) {
    if (month < 1 || month > 12) { // checks if month is within the range of 1 - 12
        return 0;
    } if (day < 1 || day > 31) { // checks if day is within the range of 1-31
        return 0;
    } if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) { //checks the months with only 30 days 
        return 0;         
    } if (month == 2) {        
        if (day > 29) {          // checks the month of February since it only has a maximum of 29 days
            return 0;           
        } if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { //checks if lep year
            if (day > 29) {
                return 0;
            }
        } else {            // checks if d
            if (day > 28) {
                return 0;
            }
        }
    }

    return 1;
}

/*
This function finds the index of the productID
@param *products is a pointer to an array of ITEM struct that represents the list of products
@param productID contains the productID to be checked
Pre-condition: 
*/

int findProduct(ITEM *products, int productID) {
    int i;
    for(i = 0; i < MAX_ITEMS; i++){
        if(products[i].productID == productID){
            return i;
        }
    }
    return -1;
}

/*
This function updates the cart with changes in item quantity and price, and prompts the user to edit their cart
@param *user a pointer to the current user of the system
@param *cart a pointer to the current cart of the user
@param *product a pointer to the array of available products
@param *transact a pointer to the transaction object of the user
@param *cartCount a pointer to the number of items in the cart
@param *itemCount a pointer to the number of available items in the database
@param productID is the ID of the product being checked out
Pre-condition: the cart and product arrays have been initialized and populated, and the cart count and item count have been properly set
*/

void checkout(USER* user, CART* cart, ITEM* product, TRANSACTION* transact, int* cartCount, int* itemCount, int productID) {
    DATE transactionDate;
    int i, j, productIndex, newQuantity;
    int validInput = 0;
    float newPrice = 0;
    char choice;
    
    while (!validInput) {
        char input_date[11]; // Allocate space for MM/DD/YYYY and null terminator

        printf("\nEnter the date of transaction (in the format MM/DD/YYYY): ");
        scanf("%10s", input_date); // Read up to 10 characters into input (leaving space for null terminator)

        int result = sscanf(input_date, "%d/%d/%d", &transactionDate.month, &transactionDate.day, &transactionDate.year);
        if (result == 3) {
            if (isDateValid(transactionDate.day, transactionDate.month, transactionDate.year)) { // Check if date is valid
                validInput = 1;
            } else {
                printf("\nInvalid date. Please try again.\n");
            }
        } else {
            printf("\nInvalid input format. Please enter date in the format MM/DD/YYYY.\n");
        }
    }

        // check for changes in item quantity and price
        for (i = 0; i < *cartCount; i++) {
            productIndex = -1;
            int found = 0; // flag variable
            // find the item in the items array
            j = 0;
            while (!found && j < *itemCount) {
                if (cart[i].item[0].productID == product[j].productID) {
                productIndex = j;
                found = 1;
            }
            j++;
        }
            // check if item still exists in the items array
    if (productIndex == -1) {
        printf("\n%s is no longer available. Please remove it from your cart.\n", cart[i].item[0].name);
        found = 0;
    } else {
        found = 1;
    }
    // only update the cart if the item is still available
    if (found) {
        
        // check for changes in item quantity
        if (cart[i].item[0].productQuantity > product[productIndex].productQuantity) {
            printf("\n%s quantity has changed from %d to %d. \nPlease review your cart.\n", product[productIndex].name, cart[i].item[0].productQuantity, product[productIndex].productQuantity);
            newQuantity = product[productIndex].productQuantity;
        
        } else {
            newQuantity = cart[i].item[0].productQuantity;
        }
        
        // check for changes in item price
        if (cart[i].item[0].unitPrice != product[productIndex].unitPrice) {
            printf("\n%s price has changed from ₱%6.2f to ₱%6.2f. \nPlease review your cart.\n", product[productIndex].name, cart[i].item[0].unitPrice, product[productIndex].unitPrice);
            newPrice = product[productIndex].unitPrice;
        
        } else {
            newPrice = cart[i].item[0].unitPrice;
        }
        
        // update changes in cart
        cart[i].item[0].productQuantity = newQuantity;
        cart[i].item[0].unitPrice = newPrice;
        cart[i].transact.date = transactionDate;
    }
}
    printf("\nWould you like to edit your cart? Press Y for Yes, or N for No): ");
    scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            editCart(user, product, cart, cartCount);
    
        } else if (choice == 'N' || choice == 'n') {
            return;
    
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
}

/*
This function remove item from cart 
@param *cart a pointer to the current cart of the user
@param *cartCount a pointer to the number of items in the cart
@param index
Pre-condition: 
*/

void removeCartItem(CART *cart, int *cartCount, int index) {
    if (index < 0 || index >= *cartCount) {
        return;
    }// shift all items after index one position to the left

    for (int i = index; i < *cartCount - 1; i++) {
    cart[i] = cart[i + 1];
    }   
    // reduce cart count by1
    *cartCount -= 1;
}

/*
This function transacts all the items in the cart of the user 
@param *cart a pointer to the current cart of the user
@param *product a pointer to the array of available products
@param *cartCount a pointer to the number of items in the cart 
@param *itemCount a pointer to the number of available items in the database
Pre-condition: each transaction will contain all items from the same seller only
*/

// only prints from one seller
void processTransactionSummaryALL(CART *cart, ITEM *product, int *cartCount, int *itemCount) {
    int i, j, k, sellerID;
    double totalAmountDue;
    

    // loop through all items in cart and group them by sellerID
    for (i = 0; i < *cartCount; i += MAX_ITEMS_TRANSACTION) {
       
        // get sellerID of first item in transaction
        sellerID = cart[i].item[0].sellerID;
       
        // initialize transaction with sellerID and date
        TRANSACTION transact;
        transact.date = cart->transact.date;
        transact.sellerID = sellerID;

        // loop through all items from the same seller and add them to transaction
        for (j = i; j < *cartCount && j < i + MAX_ITEMS_TRANSACTION && cart[j].item[0].sellerID == sellerID; j++) {
            // update productQuantity in ITEM array
            int productIndex = -1;
            int found = 0;
            for (k = 0; k < *itemCount; k++) {
                if (product[k].productID == cart[j].item[0].productID) {
                    productIndex = k;
                    found = 1;
                }
            }
            if (found == 1 && productIndex != -1) {
                product[productIndex].productQuantity -= cart[j].item[0].productQuantity;
            }
            
            found = 0;

            // add item to transaction
            transact.item[j-i] = cart[j].item[0];
            transact.item[j-i].productQuantity = cart[j].item[0].productQuantity;
        }

        // calculate total amount due for transaction
        totalAmountDue = 0;
        for (int k = i; k < j; k++) {
            totalAmountDue += transact.item[k-i].unitPrice * transact.item[k-i].productQuantity;
        }
        transact.totalAmount = totalAmountDue;

        // print transaction summary
        printf("\n");
        printf("+--------------------------------------------------------------------------------------+\n");
        printf("|                                TRANSACTION SUMMARY                                   |\n");
        printf("+--------------------------------------------------------------------------------------+\n");
        printf("| Date: %02d/%02d/%04d | Seller ID: %-5d | Seller Name: %-20.20s |\n", transact.date.month, transact.date.day, transact.date.year, transact.sellerID, transact.user.name); // replace "Seller Name" with actual seller name
        printf("+--------------------------------------------------------------------------------------+\n");
        printf("|%-10s| %-25.20s| %-20.16s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "UNIT PRICE", "QUANTITY");
        printf("+--------------------------------------------------------------------------------------+\n");
        for (int k = i; k < j; k++) {
            printf("|%-10d| %-25.20s| %-20.16s| ₱%-12.2f| %-10d|\n", transact.item[k-i].productID, transact.item[k-i].name, transact.item[k-i].category, transact.item[k-i].unitPrice, transact.item[k-i].productQuantity);
        }
        printf("+--------------------------------------------------------------------------------------+\n");
        printf("| Total Amount Due: ₱%-9.2f                                                         |\n", totalAmountDue);
        printf("+--------------------------------------------------------------------------------------+\n");

        // remove items from cart
        for (int k = i; k < j; k++){
            removeCartItem(cart, cartCount, k);
        }
    }
}

/*
This function transacts all items in the cart of the user from the same seller 
@param 
@param 
@param 
Pre-condition: each transaction will contain all items from the same seller only
*/

void processTransactionSELLER(CART *cart, ITEM *product, int *cartCount, int *itemCount) {
    int sellerID;
    double totalAmountDue;
    int i, k;

    printf("\nEnter the Seller ID: ");
    scanf("%d", &sellerID);


    // loop through all items in cart and group them by sellerID
    for (i = 0; i < *cartCount; i++) {

        // get sellerID of first item in transaction
        int currentSellerID = cart[i].item[0].sellerID;

        // check if the seller ID matches
        if (currentSellerID == sellerID) {

            // initialize transaction with sellerID and date
            TRANSACTION transact;
            transact.date = cart[i].transact.date;
            transact.sellerID = sellerID;

            // loop through all items from the same seller and add them to transaction
            int j = i;
            int itemIndex = 0;
            while (j < *cartCount && j < i + MAX_ITEMS_TRANSACTION && cart[j].item[0].sellerID == sellerID) {

                // update productQuantity in ITEM array
                int productIndex = -1;
                int found = 0;
                for (k = 0; k < *itemCount && productIndex == -1; k++) {
                    if (product[k].productID == cart[j].item[0].productID) {
                        productIndex = k;
                        found = 1;
                    }
                }
                if (found == 1 && productIndex != -1) {
                    product[productIndex].productQuantity -= cart[j].item[0].productQuantity;
                }
                found = 0;
                // add item to transaction
                transact.item[itemIndex] = cart[j].item[0];
                transact.item[itemIndex].productQuantity = cart[j].item[0].productQuantity;
                itemIndex++;
                
                j++;
            }

            // calculate total amount due for transaction
            totalAmountDue = 0;
            for (int k = 0; k < itemIndex; k++) {
                totalAmountDue += transact.item[k].unitPrice * transact.item[k].productQuantity;
            }
            transact.totalAmount = totalAmountDue;

            // print transaction summary
            printf("\n");
            printf("+--------------------------------------------------------------------------------------+\n");
            printf("|                                TRANSACTION SUMMARY                                   |\n");
            printf("+--------------------------------------------------------------------------------------+\n");
            printf("| Date: %02d/%02d/%04d | Seller ID: %-5d |\n", transact.date.month, transact.date.day, transact.date.year, transact.sellerID);
            printf("+--------------------------------------------------------------------------------------+\n");
            printf("|%-10s| %-25.20s| %-20.16s| %-13s| %-10s|\n", "PRODUCT ID", "NAME", "CATEGORY", "UNIT PRICE", "QUANTITY");
            printf("+--------------------------------------------------------------------------------------+\n");
            for (int k = 0; k < itemIndex; k++) {
                printf("|%-10d| %-25.20s| %-20.16s| ₱%-12.2f| %-10d|\n", transact.item[k].productID, transact.item[k].name, transact.item[k].category, transact.item[k].unitPrice, transact.item[k].productQuantity);
            }
            printf("+--------------------------------------------------------------------------------------+\n");
            printf("| Total Amount Due: ₱%-9.2f     |                                                 |\n", transact.totalAmount);
            printf("+--------------------------------------------------------------------------------------+\n");

        }
    }
}


/*
This function transacts a specific item the user wants to check out
@param 
@param 
@param 
Pre-condition:  user is asked to input the product ID of the item he had included in the cart to check out
*/

void processTransactionSummaryITEM(){

}

/*
This function is used to handle the checkout process of the user's cart
@param users[] an array of USER structs representing the users in the database
@param transact[] an array of TRANSACTION structs representing the transactions made in the database
@param cart[] an array of CART structs representing the current user's cart
@param *product a pointer to an array of ITEM structs representing the items available for purchase
@param cartCount an integer representing the number of items in the current user's cart
@param itemCount an integer representing the number of items available for purchase
@param transactionCount an integer representing the number of transactions made in the database
@param userCount an integer representing the number of users in the database
@param productID an integer representing the ID of the product being checked out
Pre-condition:  user is asked to input the product ID of the item he had included in the cart to check out
*/

void checkoutMenu(USER users[], TRANSACTION transact[], CART cart[], ITEM *product, 
                int cartCount, int itemCount, int transactionCount, int userCount, int productID){

    int choice = 0;
    checkout(users, cart, product, transact, &cartCount, &itemCount, productID);
    
    while(choice != 4){
        displayCheckOutMenu(&choice);

        switch(choice){

            case 1: 
                processTransactionSummaryALL(cart, product, &cartCount, &itemCount);
                break;
            
            case 2:
                processTransactionSELLER(cart, product, &cartCount, &itemCount);
                break;

            case 3:
                break;

            case 4:
                break;
            
            default:
                break;
        }
    }
}



/*
This function asks the user for password as verification
@param USER users[] is an array of USER struct and represents the list of registered users
@param int num_users is an integer that represents the number of users registered 
@param sellerID contains the sellerID that needs to be checked
Pre-condition: the user is assumed to be the administrator of the program
*/

int adminMenu(int num_users, USER users[MAX_USERS], int sellerID){
    int i;
    USER newUser;

    printf("\nEnter your password: ");
    scanf("%s", newUser.password);

    for(i = 0; i < num_users; i++){
        if(strcmp(users[i].password, newUser.password) == 0){
            printf("\nLogin successful!\n");
            sellerID = users[i].userID;
            return 1;
        }
    }
    printf("\nUnauthorized access not allowed\n\n");
    return -1;
}

/*
This function shows all the users arranged by user ID
@param USER users[] is an array of USER struct and represents the list of registered users
@param int *num_users is a pointer to an integer and represents the number of registered 
Pre-condition: users array contains valid USER structs and the num_users integer pointer points to the correct number of registered users
*/

void viewAllUsers(int num_users, USER users[MAX_USERS]){
    
    int i, j;
    
    // sort the users by userID in ascending order using bubble sort
    for (i = 0; i < num_users - 1; i++) {
        for (j = i + 1; j < num_users; j++) {
            if (users[i].userID > users[j].userID) {
                // Swap the users
                USER temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
    }
    
    printf("\n");
    printf("+---------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                  ALL USERS                                              |\n");
    printf("+---------------------------------------------------------------------------------------------------------+\n");
    printf("|%-10s| %-15s| %-25.20s| %-35.30s| %-12s|\n", "USER ID", "PASSWORD", "NAME", "ADDRESS", "PHONE NUMBER");
    printf("+---------------------------------------------------------------------------------------------------------+\n");

    for (i = 0; i < num_users; i++) {
        printf("|%10d| %-15s| %-25.20s| %-35.30s| %12d|\n", 
                                            users[i].userID, 
                                            users[i].password, 
                                            users[i].name, 
                                            users[i].address, 
                                            users[i].contactNum);        
        printf("+---------------------------------------------------------------------------------------------------------+\n");
    }
}

/*
This function shows all the users who have items to be sold
@param int num_users an integer that represents the number of users registered 
@param int num_items an integer that represents the number of items registered 
@param users[] is an array of USER struct and represents the list of registered users
@param products[] is an array of ITEM struct and represents the list of registered items
Pre-condition:  num_users must be the total number of registered users and users must be an array of USER struct representing the list of registered users
                num_items must be the total number of available items and products must be an array of ITEM struct representing the list of available items
                All USER struct objects in the users array must have valid userID, password, name, address, and contactNum fields
                All ITEM struct objects in the products array must have valid itemID, sellerID, name, category, price, and stock fields
                userID field of each ITEM struct object in the products array must match the userID field of a corresponding USER struct object in the users array
*/

void viewAllSellers(int num_users, int num_items, USER users[MAX_USERS], ITEM products[]) {

    int i, j;

    // sort the users by userID in ascending order using bubble sort
    for (i = 0; i < num_users - 1; i++) {
        for (j = i + 1; j < num_users; j++) {
            if (users[i].userID > users[j].userID) {
                // Swap the users
                USER temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
    }

    // count the number of sellers with items for sale
    int num_sellers = 0;
    for (i = 0; i < num_users; i++) {
        int numItemsForSale = 0;
        for (j = 0; j < num_items; j++) {
            if (products[j].sellerID == users[i].userID) {
                numItemsForSale++;
            }
        }

        if (numItemsForSale > 0) {
            num_sellers++;
        }
    }

    printf("\n");
    printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                           ALL SELLERS                                                         |\n");
    printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|%-10s| %-15s| %-25.20s| %-30s| %-12s| %-25s|\n", "USER ID", "PASSWORD", "NAME", "ADDRESS", "PHONE NUMBER", "NUMBER OF ITEMS FOR SALE");
    printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");

    for (i = 0; i < num_users; i++) {
        int numItemsForSale = 0;
        for (j = 0; j < num_items; j++) {
            if (products[j].sellerID == users[i].userID) {
                numItemsForSale++;
            }
        }

        if (numItemsForSale > 0) {
            printf("|%10d| %-15s| %-25.20s| %-30s| %12d| %25d|\n",
                   users[i].userID,
                   users[i].password,
                   users[i].name,
                   users[i].address,
                   users[i].contactNum,
                   numItemsForSale);
            printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
        }
    }
}

/*
This function shows 
@param 
@param 
@param 
Pre-condition: 
*/

void viewTotalSalesDuration(){

}

/*
This function shows 
@param 
@param 
@param 
Pre-condition: 
*/

void viewSellerSales(){

}

/*
This function shows 
@param 
@param 
@param  
Pre-condition: 
*/

void viewShopaholics(){

}

// MAIN FUNCTION
int main(){
    USER users[MAX_USERS];
    ITEM products[MAX_ITEMS];
    CART cart[MAX_CART_ITEMS];
    TRANSACTION transact[MAX_ITEMS_TRANSACTION];

    int num_users = 0;
    int num_items = 0;
    int num_cart = 0;
    int num_transactions = 0;
    int choice = 0;
    int usermenuchoice = 0; 
    int usersellmenuchoice = 0;
    int userbuymenuchoice = 0;
    int adminmenuchoice = 0;
    int sellerID = 0;
    int productID = 0;

    readUsersFile(&num_users, users);
    readItemsFile(&num_items, products);

    while (choice != 4){ 
        displayMainMenu(&choice);
        switch(choice){
        printf("\n");

        case 1: // User Registration
            userRegister(users, &num_users);
            break;
            
        case 2: // User Menu
            if (userMenu(num_users, users, &sellerID) == 1){
            printf("\n");
            displayUserMenu(&usermenuchoice);
            printf("\n");
                
                switch(usermenuchoice){
                    case 1: // Sell Menu
                        do {
                            displayUserSellMenu(&usersellmenuchoice);
                            switch (usersellmenuchoice) {
                                case 1:
                                    addNewItem(users, products, &num_items, users->userID, sellerID, &num_users);
                                    printf("\n");
                                    break;
                                
                                case 2:
                                    editStock(products, sellerID, &num_items);
                                    printf("\n");
                                    break;
                                
                                case 3:
                                    displayMyProducts(products, sellerID, &num_items);
                                    printf("\n");
                                    break;
                                
                                case 4:
                                    displayLowStockProducts(products, num_items, sellerID);
                                    printf("\n");
                                    break;
                                
                                case 5:
                                    printf("\n");
                                    break;
                                
                                default:
                                    printf("\nInvalid input. Please input again\n");
                                    break;
                            }
                        } while (usersellmenuchoice != 5);
                        break;
                    
                    case 2: // Buy Menu
                        do{
                            displayUserBuyMenu(&userbuymenuchoice);
                            switch(userbuymenuchoice){
                                case 1:
                                    viewAllProducts(products, num_items, sellerID);
                                    break;

                                case 2:
                                    searchProductSpecificSeller(sellerID, num_items, products);
                                    break;

                                case 3:
                                    searchProductCategory(num_items, products);
                                    break;

                                case 4:
                                    searchProductName(products, num_items);
                                    break;

                                case 5:
                                    addtoCart(users, products, cart, num_items, &num_cart, sellerID);
                                    break;

                                case 6:
                                    editCart(users, products, cart, &num_cart);
                                    break;
                                
                                case 7:
                                    checkoutMenu(users, transact, cart, products, num_cart, num_items, num_transactions, num_users ,productID);
                                    break;
                                
                                case 8:
                                    break;

                                default:
                                    printf("\nInvalid input. Please input again\n");
                                    break;
                            }
                        } while (userbuymenuchoice != 8);
                        break;
                    
                    case 3: // Exit User Menu
                        printf("\n"); 
                        break;
                    
                    default: 
                        printf("\nInvalid input. Please input again\n");
                        displayMainMenu(&choice);
                        break;
                }
            }
            break;

        case 3: // Admin Menu
            if (adminMenu(num_users, users, sellerID) == 1){
                do {
                    displayAdminMenu(&adminmenuchoice);

                    switch (adminmenuchoice) {
                        case 1: 
                            viewAllUsers(num_users, users);
                            printf("\n");
                            break;

                        case 2:
                            viewAllSellers(num_users, num_items, users, products);
                            printf("\n");
                            break;

                        case 3:
                            viewTotalSalesDuration();
                            printf("\n");
                            break;

                        case 4:
                            viewSellerSales();
                            printf("\n");
                            break;

                        case 5:
                            viewShopaholics();
                            printf("\n");
                            break;

                        case 6:
                            printf("\n");
                            break;

                        default:
                            printf("\nInvalid input. Please input again\n");
                            break;
                    }
                } while (adminmenuchoice != 6);
            }
            break; 
                
            case 4: // Exit Program
                saveUsersDataFiles(num_users, users);
                saveItemsDataFiles(num_items, products);
                printf("\n                                Going so soon?\n");
                printf("                       You'll be back to shop again... right?\n");
                return 0;
                
            default:
                printf("\n                     Invalid choice, please try again.\n");
            }
    }
    
    return 0;
}