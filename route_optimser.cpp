#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
#include<algorithm>
#include <ncurses.h>
#include <thread>
#include <random>
#include <chrono>

//defined infinity as constant 999999999
#define infinity 999999999

using namespace std;

struct store
{
 long long int cost[20];
 int array[20];
}

//Array of store data type
travel[15];

struct originaldata{
 long long int cost[20];
}

//array of originaldata
 ini[15];

//for getting random numbers of 10 digit for Flight Id
 long long randomnumber(){

 const long long lower_bound = 999999999;
 const long long upper_bound = 9999999999;

 // Create a random number generator
 random_device rd; // Seed for the random number engine
 mt19937 gen(rd()); // Standard mersenne_twister_engine
 uniform_int_distribution<long long> dist(lower_bound, upper_bound);

 // Generate a random number
 long long random_number = dist(gen);
 return random_number;
 }
 
 //to change color of the text
 void changeColor(int colorCode) {
 std::cout << "\033[38;5;" << colorCode << "m"; // Change text color
}

//to reset color already selected
void resetColor() {
 std::cout << "\033[0m"; // Reset to default color
}

class datam{
 public:

 //array for initializing cities
 string places[15];
 
 //datam() constructor is used to initialize values of cities...
 
 datam():places{"Delhi","Mumbai","Chennai","Kolkata","Kerala","Hyderabad","Pune","Goa","Bangalore","Amritsar","Jaipur","Patna","Puducherry","Srinagar","Bhopal"}{}
 
 void costdeclaration(){
 int N,i,j;
 N=15;
 
 //Ten different major cities are considered

 //The cost of travelling between any two cities in direct flight is initialized. In further steps the minimum fare will be calculated

 long long int arr[15][15]={{0,3500,2000,infinity,1000,infinity,infinity,infinity,infinity,7000,4000,1500,infinity,6500,infinity},

 {3500,0,infinity,1520,infinity,infinity,infinity,2500,infinity,infinity,infinity,infinity,infinity,infinity,5000},

 {2000,infinity,0,1500,infinity,3000,infinity,infinity,infinity,infinity,2000,1000,infinity,infinity,1500},

 {infinity,1520,1500,0,infinity,1200,4500,infinity,6000,infinity,infinity,infinity,infinity,infinity,1000},

 {1000,infinity,infinity,infinity,0,1500,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},

 {infinity,infinity,3000,1200,1500,0,1950,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},

 {infinity,infinity,infinity,4500,infinity,1950,0,infinity,infinity,2050,infinity,infinity,infinity,infinity,infinity},

 {infinity,2500,infinity,infinity,infinity,infinity,infinity,0,5000,infinity,infinity,infinity,infinity,infinity,infinity},

 {infinity,infinity,infinity,6000,infinity,infinity,infinity,5000,0,7000,infinity,infinity,infinity,infinity,infinity},

 {7000,infinity,infinity,infinity,infinity,infinity,2050,infinity,7000,0,infinity,infinity,infinity,infinity,infinity},

 {4000,infinity,2000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity,infinity,infinity},

 {1500,infinity,1000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity,infinity},

 {infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity},

 {6500,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity},

 {infinity,5000,1500,1000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0}};

 //the main array i.e. arr is not changed. Instead, the values are copied to structure and then the structure store with data member cost is changed. The structure store will hold the
 //minimum possible fare between any origin and destination

 for(i=0;i<N;i++)
 {
 for(j=0;j<N;j++)
 {
 //initializing travel and ini
 travel[i].cost[j]=arr[i][j];
 travel[i].array[j]=j;
 ini[i].cost[j]=arr[i][j];
 }
 }
 }
};

//graph implementation

//used to get the minimum distance and fare path with two destinations

//OOPs concept of inheritance is used here to inherit modules from datam

class bellmanfordalgorithm:public datam{
 public:

 int N,i,j,k; 

 //bellmanfordalgorithm constructor to set N as 15
 bellmanfordalgorithm(){
 N=15;
 }

 void algorithmic_implementation(){
 
 //3 different loops are executed

 //first loop for iterating departure cities
 for(i=0;i<N;i++){

 //second loop for iterating destination cities
 for(j=0;j<N;j++){

 //third loop for iterating internediate cities for checking shorted path and fare
 for(k=0;k<N;k++){

 if(travel[i].cost[j]>travel[i].cost[k]+travel[k].cost[j])
 {
 //if low fare is found for the same origin and destination, the minimum possible fare is changed.
 
 travel[i].cost[j]=travel[i].cost[k]+travel[k].cost[j];
 travel[i].array[j]=k;
 }
 }
 }
 }
 }
};

//for storing login credentials inorder to login after creating an account

class filehandlingmodule{
 public:
 
 string username1,password1;

 //for valifying the password and username 

 // login.txt file is being read

 bool log_in(string username,string password){
 ifstream fileread;
 fileread.open("login.txt");

 //for fetching username and password into username1 and password1 respectively
 while(fileread>>username1>>password1){

 if((username==username1)&&(password==password1)){

 changeColor(2);
 cout<<endl<<" Account Login Successful..."<<endl;
 resetColor();
 return true;
 }
 }
 changeColor(1);

 //either password or username did not match
 cout<<endl<<" Account Login Failed..."<<endl;
 resetColor();
 return false;
 }

 //for creating a new account in the system


 void createaccount(string username,string password){

 ofstream filewrite;
 filewrite.open("login.txt",ios::app);
 filewrite<<username<<" "<<password<<"\n";
 filewrite.close();
 changeColor(2);
 cout<<endl<<" Account Created ..."<<endl;

 //account successfully created
 resetColor();
 
 }


 //here the file is being written using append mode

 void ticket(string username,string firstname[],string lastname[],string sex[],int age[],int no){
 ofstream filewrite;
 filewrite.open("ticket.txt",ios::app);
 for(int i=0;i<no;i++){
 filewrite<<username<<" "<<firstname[i]<<" "<<lastname[i]<<" "<<sex[i]<<" "<<age[i]<<"\n";
 }
 filewrite.close();
 }
};

//asks for user input for user's choices

class inputmodule{
 public:

 string source,destination;
 string username,password;
 

 void user_input(string userchoice[]){
 system("clear");
 changeColor(3);

 cout<<"\n\n **************************** Welcome to Flight Management System **************************"<<endl;
 cout<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" Enter Your places:";

 resetColor();
 cin>>source;
 changeColor(3);

 cout<<" *****************************************"<<endl;
 cout<<" Enter Your Destination:";

 resetColor();
 cin>>destination;
 changeColor(3);

 cout<<" *****************************************"<<endl;
 resetColor();

 userchoice[0]=source;
 userchoice[1]=destination;
 }
 string login(){
 while(1){
 changeColor(198);

 cout<<"\n\n **************************** Welcome to Flight Management System **************************"<<endl;
 cout<<"\n\n\n\n";
 cout<<" ENTER "<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" **** 1. To Login *****"<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" **** 2. To Create New Account ****"<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" **** 3. To Exit ****"<<endl;
 cout<<" *****************************************"<<endl;
 cout<<"\n Enter Your Choice:";
 resetColor();

 int ch;
 bool res;
 filehandlingmodule fobj;
 cin>>ch;

 switch(ch){

 case 1:

 system("clear");
 changeColor(208);
 cout<<"\n\n **************************** Welcome to Flight Management System **************************"<<endl;
 cout<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" Enter Username:";
 cin>>username;
 resetColor();

 changeColor(208);
 cout<<" *****************************************"<<endl;
 cout<<" Enter Your Password:";
 resetColor();
 cin>>password;

 changeColor(208);
 cout<<" *****************************************"<<endl;
 resetColor();

 //calling log_in function from filehandlingmodule
 res=fobj.log_in(username,password);
 break;

 case 2:

 system("clear");
 changeColor(10);
 cout<<"\n\n **************************** Welcome to Flight Management System **************************"<<endl;
 cout<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" Enter Username:";
 resetColor();
 cin>>username;

 changeColor(10);
 cout<<" *****************************************"<<endl;
 cout<<" Enter Your Password:";
 resetColor();
 cin>>password;
 
 changeColor(10);
 cout<<" *****************************************"<<endl;
 resetColor();
 fobj.createaccount(username,password);
 break;

 case 3:

 exit(0);
 break;

 }
 if(res==true)
 return username;
 resetColor();
 }
 }

 // to get total number of passengers travelling

 int noofpassenger(){

 changeColor(202);
 int no;
 changeColor(202);
 cout<<endl<<" Enter the no of passengers:";
 resetColor();
 cin>>no;
 return no;
 resetColor();
 }
 
};

class outputm{
 public:

 string source,destination;
 void initial(){
 system("clear");

 changeColor(198);
 cout<<"\n\n **************************** Welcome to Travel Management System **************************"<<endl;
 cout<<"\n\n";
 cout<<" ***************************"<<endl;
 cout<<" * Facilities Available: *"<<endl;
 cout<<" ***************************"<<endl;
 cout<<"\n\n";
 cout<<" ENTER "<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" **** 1. To Display List of Cities ****"<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" **** 2. To Book Ticket ****"<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" **** 3. To Exit ****"<<endl;
 cout<<" *****************************************"<<endl;
 resetColor();

 }
 void list_cities(int N){

 datam o;
 cout<<endl;
 system("clear");
 cout<<"\n\n **************************** Welcome to Travel Management System **************************"<<endl;
 cout<<"\n\n";
 cout<<" The listed cities are:"<<endl;
 cout<<" *****************************************"<<endl;

 for(int i=0;i<N;i++){
 cout<<" * "<<o.places[i]<<" "<<endl;
 cout<<" *"<<endl;
 }

 cout<<" *****************************************"<<endl;
 }
 
 void ticket(int total_price,int no,string source,string destination,string username){
 system("clear");
 changeColor(45);

 cout<<"\n\n **************************** E-TICKET **************************"<<endl;
 cout<<endl<<" This Ticket is issued for :"<<username<<endl;
 cout<<endl<<" Source:"<<source<<endl;
 cout<<endl<<" Destination:"<<destination<<endl;
 cout<<endl<<" Total No of Passengers:"<<no<<endl;
 cout<<endl<<" Total Cost:"<<total_price<<endl;
 
 cout<<"\n\n ****************************************************************************"<<endl;
 cout<<"\n";
 resetColor();
 }
 
 void passengerdetailedticket(int no,string firstname[],string lastname[],string sex[],int age[]){
 for(int i=0;i<no;i++){
 changeColor(154);

 cout<<" Passenger "<<(i+1)<<" Details:"<<endl<<endl;
 cout<<" First Name: "<<firstname[i]<<endl;
 cout<<" Last Name: "<<lastname[i]<<endl;
 cout<<" Sex: "<<sex[i]<<endl;
 cout<<" Age: "<<age[i]<<endl;
 cout<<" Flight ID: "<<randomnumber()<<endl;
 resetColor();
 cout<<"\n\n ****************************************************************************"<<endl;
 }
 int ch;
 cout<<endl<<" Enter 1 to continue:";
 cin>>ch;

 if(ch==1){
 initial();
 }
 }
 
 int display_price(string source,string destination,int N,string username){
 source=source;
 destination=destination;
 datam o;
 inputmodule in;
 int i,j,choiceofpassenger;
 for(i=0;i<N;i++){
 for(j=0;j<N;j++){
 if(source==o.places[i] && destination==o.places[j]){
 cout<<endl;
 if(ini[i].cost[j]==infinity){
 changeColor(202);
 cout<<" There is no direct flight from "<<source<<" to "<<destination<<". So, Travel via other cities is only possible."<<endl;
 resetColor();
 changeColor(3);
 cout<<" The Price is:"<<travel[i].cost[j]<<endl<<endl;
 cout<<" The Route is:"<<source;
 resetColor();
 int c1=i,c2=j;
 while(c1!=c2){
 cout<<"-->"<<o.places[travel[c1].array[j]];
 c1=travel[c1].array[j];
 }
 cout<<endl<<endl;
 }
 else if((ini[i].cost[j]!=infinity)&&(ini[i].cost[j]==travel[i].cost[j])){
 changeColor(45);
 cout<<" There is direct flight available from "<<source<<" to "<<destination<<" . And,it is cheapest among all other paths..."<<endl;
 cout<<" The Price is:"<<travel[i].cost[j]<<endl;
 resetColor();
 }
 else if((ini[i].cost[j]!=infinity)&&(ini[i].cost[j]>travel[i].cost[j])){
 changeColor(131);
 cout<<" There is direct flight available from "<<source<<" to "<<destination<<" ."<<endl;
 cout<<" The Price is:"<<ini[i].cost[j]<<endl<<endl;
 cout<<" *****************************************"<<endl<<endl;
 cout<<" You can go via other cities that will cost you less than direct flight."<<endl;
 cout<<" The Price is:"<<travel[i].cost[j]<<endl<<endl;
 cout<<" The Route is:"<<source;
 resetColor();
 int c1=i,c2=j;
 while(c1!=c2){
 cout<<"-->"<<o.places[travel[c1].array[j]];
 c1=travel[c1].array[j];
 }
 cout<<endl<<endl;
 cout<<" Press 1 to go by direct flight and Press 2 to go via other cities: ";
 cin>>choiceofpassenger;
 }
 char c;
 cout<<endl;
 cout<<" Do You want to Continue(Y/N)?";
 cin>>c;
 if(c=='Y'){
 int no=in.noofpassenger();
 string firstname[no],lastname[no],sex[no];
 int age[no];
 for(int i=0;i<no;i++){
 changeColor(14);
 cout<<endl;
 cout<<" *****************************************"<<endl;
 cout<<" Passenger "<<(i+1)<<":"<<endl<<endl;
 cout<<" First Name:";
 cin>>firstname[i];
 cout<<endl<<" Last Name:";
 cin>>lastname[i];
 cout<<endl<<" Sex(Male/Female/Other):";
 cin>>sex[i];
 cout<<endl<<" Age:";
 cin>>age[i];
 resetColor();
 }
 int total_price;
 if(choiceofpassenger==1){
 total_price=no*ini[i].cost[j];
 }
 else{
 total_price=no*travel[i].cost[j];
 }
 cout<<endl<<" The total Price is:"<<total_price<<endl;
 char y;
 cout<<" Do You want to confirm Your Ticket(Y/N)?";
 cin>>y;
 if(y=='Y'){
 filehandlingmodule f;
 f.ticket(username,firstname,lastname,sex,age,no);
 ticket(total_price,no,source,destination,username);
 passengerdetailedticket(no,firstname,lastname,sex,age);
 }
 else{
 cout<<endl<<" Thank You For choosing Us...";
 cout<<endl<<" Do You Want to Continue(Y/N)?";
 char ch;
 cin>>ch;
 if(ch=='Y'){
 initial();
 }
 return 0;
 }
 }
 else{
 cout<<endl<<" Thank You For choosing Us...";
 cout<<endl<<" Do You Want to Continue(Y/N)?";
 char ch;
 cin>>ch;
 if(ch=='Y'){
 initial();
 }
 }
 return 0;
 }
 }
 }
 cout<<" Sorry, There are no flights available connecting the cities..."<<endl;
 cout<<endl<<" Do You Want to Continue(Y/N)?";
 char ch;
 cin>>ch;
 if(ch=='Y'){
 initial();
 }
 return 0;
 }
};

void printBorder(int width, char symbol) {
 for (int i = 0; i < width; ++i) {
 cout << symbol;
 cout << symbol;
 }
 cout << endl;
}

void animate() {
 initscr(); // Initialize ncurses mode
 timeout(100); // Set the screen refresh time (in ms)
 noecho(); // Disable automatic echo of typed characters
 curs_set(0); // Hide the cursor

 int height, width;
 getmaxyx(stdscr, height, width); // Get screen size

 for (int i = 0; i < width ; ++i) {
 clear(); // Clear the screen
 attron(COLOR_PAIR(1)); // Activate color pair 1
 mvprintw(height / 2, i, "********** Welcome to Flight Management System **********"); // Move text and print
 attroff(COLOR_PAIR(1)); // Deactivate color pair 1
 refresh(); // Refresh the screen to display changes

 std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Delay
 }

 endwin(); // Close ncurses
}


int main(){
 int N;
 N=15;
 const int pageWidth = 60; // Width of the welcome page
 const char borderChar = '='; // Character used for border design
// Print the top border
 
 if (has_colors()) {
 start_color(); // Initialize color functionality
 init_pair(1, COLOR_RED, COLOR_BLACK); // Define color pair (foreground, background)
 }
 
 animate();
 // Print welcome messages centered

 printBorder(pageWidth, borderChar);
 changeColor(10);
 cout<<"\n*---*****----------------~~~~~~~~~~~~***** Welcome to Flight Management System *****~~~~~~~~~~~~~--------------*****---*\n";
 resetColor();
 cout<<endl;
 printBorder(pageWidth, borderChar);
 cout<<endl;
 changeColor(11);
 cout<<" This system helps to manage flight operations, passenger management, route optimization, and flight tickets booking.\n";
 changeColor(39);
 cout << " We are delighted to assist you with managing your flights!" << endl;
 resetColor();
 cout<<endl;
 printBorder(pageWidth, borderChar);
 printBorder(pageWidth, borderChar);
 cout<<endl;
 int i =0;
 changeColor(++i);

 //Details of the team members
 cout<<"Designed by -\n";
 cout<<"\n";
 resetColor();
 
 changeColor(++i);
 cout<<"Anushka Verma\n";
 cout<<"\n";
 resetColor();
 
 changeColor(++i);
 cout<<"Sambhav Jain\n";
 cout<<"\n";
 resetColor();
 
 changeColor(++i);
 cout<<"Arpita Tomar\n";
 cout<<"\n";
 resetColor();
 
 changeColor(198);
 cout<<"Anushree Sahu\n";
 cout<<"\n";
 resetColor();
 
 changeColor(203);
 cout<<"Enjoy the Experience!\n";
 cout<<"\n";
 resetColor();
 
 

 // Print the bottom border
 printBorder(pageWidth, borderChar);
 printBorder(pageWidth, borderChar);

 // Pause the screen before exiting
 cout << endl << "Press Enter to continue...";
 
 //Creating object for datam class
 
 changeColor(++i);
 
 datam obj;
 obj.costdeclaration();
 
 resetColor();
 
 //Creating object for bellmanfordalgorithm class
 
 bellmanfordalgorithm ob;
 ob.algorithmic_implementation();
 
 string userchoice[2];
 
 //Creating object for inputmodule class
 inputmodule obj1;
 
 string username;
 username=obj1.login();
 //Creating object for outputm
 outputm object;
 changeColor(++i);
 object.initial();
 
 while(1){
 int choice;
 cout<<"\n Enter Your Choice:";
 cin>>choice;
 switch(choice){
 case 1:
 object.list_cities(N);
 cout<<"\n\n Press 1 to Continue...";
 int cont;
 cin>>cont;
 if(cont==1){
 object.initial();
 }
 break;
 case 2:
 obj1.user_input(userchoice);
 //passing user inputted source and destination to display_price function of outputm
 object.display_price(userchoice[0],userchoice[1],N,username);
 break;
 case 3:
 exit(0);
 break;
 }
 }
 resetColor();
return 0;
}
