#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>

using namespace std;


class linkednode {
	public:
	linkednode *next;
	int count;
	float latitude;
	float longitude;
	linkednode(){
		next = NULL;
		count = 0;
		latitude = 0.0;
		longitude = 0.0;
	}
	linkednode(double lat, double lon){
		next = NULL;
		count = 0;
		latitude = lat;
		longitude = lon;
	}
};
class linkedlist {
	public:
		linkednode *head;
		linkedlist(){
			head = NULL;
		}
		void insert(double lat,double lon){
			linkednode *n = new linkednode(lat,lon);
			
			if(head==NULL){
				head = n;
			}else{
				n->next= head;
				head= n;
			}
		}
		
		bool search(double lat,double lon){
			if(head==NULL){
				return false;
			}
			linkednode *temp = head;
			while(temp!=NULL){
				if(temp->latitude==lat && temp->longitude==lon){
					temp->count++;
					return true;
				}
				temp  = temp->next;
			}
			return false;
		}
		void checkMax(){
			linkednode *temp = head;
			int max=0;
			while(temp!=NULL){
				if(max<temp->count){
					max= temp->count;
				}
				temp= temp->next;
			}
		   temp = head;
		   while(temp!=NULL){
		   	if(temp->count==max){
		   		cout<<"Location with most visitors : "<<temp->latitude<<","<<temp->longitude<<endl;
		   		break;
			   }
			   temp = temp->next;
		   }
			
		}
};
class node {
	public:
		int paytype;
	float data;
	string time;
	float distance;
	int passCount;
	string dtime;
	double dlatitude;
	double dlongitude;
	node *right;
	node *left;
	node(){
		paytype=0;
		distance=0;
		data = 0;
		dtime="";
		time = "";
		passCount = 0;
		right = NULL;
		left = NULL;
	}
	node(float val,int pass,string t,string d,float dist,int pt,double dlat,double dlon){
		data = val;
		paytype=pt;
		distance=dist;
		time = t;
		dtime=d;
		passCount = pass;
		dlatitude = dlat;
		dlongitude = dlon;
	   right = NULL;
		left = NULL;
	}
};

class BST {
	public:
		static int count;
		static float sum;
		static int index;
		static int cash;
		static int card;
		static int profit;
	node *root;
	BST(){
		root=NULL;
	}
	bool isEmpty(){
		return root==NULL;
	}
	void insertNode(float val,int pass,string time,string dt,float dis,int pt,double dlat,double dlon){
		node *n = new node(val,pass,time,dt,dis,pt,dlat,dlon);
		if(root==NULL){
			root = n;
			return;
		}
		node *temp = root;
		while(temp!=NULL){
			if(n->data<=temp->data  && temp->left==NULL){
				temp->left = n;
				break;
			}
			else if(n->data<temp->data){
				temp = temp->left;
			}
			else if(n->data > temp->data && temp->right == NULL){
				temp->right = n;
				break;
			}
			else{
				temp = temp->right;
			}
		}
}
bool searchNode(float val){
	if(root->data == val){
		cout<<"Value found"<<endl;
		return true;
	}
	else{
		node *temp = root;
		while(temp!=NULL){
			if(temp->data==val){
				cout<<"Value found"<<endl;
				return true;
			}
			else if(val < temp->data){
				temp=temp->left;
			}
			else{
				temp = temp->right;
			}
		}
		cout<<"Value not found"<<endl;
		return false;
	}
	
}

int height(node *&root){
	int lheight,rheight;
	if(root== NULL){
		return -1;
	}
	lheight = height(root->left);
	rheight = height(root->right);
	if(lheight>rheight){
		return lheight+1; 
	}else{
		return rheight+1;
	}

}
    
	node* deletenode(node *r,int val){
		if(r == NULL){
			return r;
		}
		else if(val < r->data){
			r->left = deletenode(r->left,val);
		}
		else if(val > r->data){
			r->right = deletenode(r->right,val);
		}
		else{
			if(r->left == NULL){
				node *temp = r->right;
				delete r;
				return temp;
			}
			else if(r->right==NULL){
				node *temp = r->left;
				delete r;
				return temp;
			}
			else{
			node *temp = minValuenode(r->right);
			r->data = temp->data;
			r->right=deletenode(r->right,temp->data);
			}
			
		}
		return r;
	}
	node* minValuenode(node *&r){
		node *curr = r;
		while(curr->left!=NULL){
			curr = curr->left;
		}
		return curr;
	}
	bool balancedBinaryTree(node *&root){
		int lh = height(root->left);
		int rh = height(root->right);
		int res = 0;
		if(lh>=rh){
			res = lh - rh;
		}
		else {
			res = rh - lh;
		}
		if(res<=1){
			return true;
		}
		else{
			return false;
		}
	}		
	void inorder(node *&root,int phour,int pmin,int dhour,int dmin){
		string word;
		vector<string> v1;
		if(root == NULL){
			return;
		}
		inorder(root->left,phour,pmin,dhour,dmin);
		stringstream s(root->time);
		while(getline(s,word,':')){
			v1.push_back(word);
		}
		int pickup = (phour*60)+pmin;
		int dropoff = (dhour*60)+dmin;
		int hour = stoi(v1[0]);
		int min = stoi(v1[1]);
		hour = (hour*60)+min;
		if(hour>=pickup && hour<=dropoff){
			if(root->data>0){
			sum+=root->data;
			count++;}
		}
		inorder(root->right,phour,pmin,dhour,dmin);
	}
	void inorder1(node *&r){
		if(r==NULL){
			return;
		}
		if(index<=10){
		inorder1(r->left);
		if(index==10){
			return;
		}
		if(r->data>0){
			index++;
			cout<<r->data<<"          "<<r->time<<"         "<<r->dtime<<endl;
		inorder1(r->right);
		if(index==10){
			return;
		}
		}
	}
}
	void inorder2(node *&r){
		if(r==NULL){
			return;
		}
		if(index<=10){
		inorder2(r->left);
		if(index==10){
        return;			
		}
		index++;
			cout<<r->data<<"          "<<r->time<<"         "<<r->dtime<<endl;
		inorder2(r->right);
		if(index==10){
			return;
		}
		}
}
void createlist(node *&r,linkedlist &l1){
	if(r==NULL){
		return;
	}
	createlist(r->left,l1);
    if(l1.search(r->dlatitude,r->dlongitude)){
    	;
	}else{
			l1.insert(r->dlatitude,r->dlongitude);
	}
	createlist(r->right,l1);
	
	
}


void inorder3(node *&r){
	if(r==NULL){
		return;
	}
	inorder3(r->left);
	if(r->paytype==1){
		cash++;
	}else{
		card++;
		profit+=r->data;}
	inorder3(r->right);
}
void companyProfit(){
	cash = 0;
	card = 0;
	profit = 0;
	inorder3(root);
	cout<<"Total Payment through Credit Card (subscribers) : "<<profit<<endl;
	int salary = 150;
	cout<<"Average Salary of Drivers : "<<salary<<"$"<<endl;
	salary = 150 * 10;
	profit = profit-salary;
	float cp = profit*0.15;
	profit = profit-cp;
	cout<<"Total Company Profit : "<<cp<<endl;
	cout<<"Total Driver's Profit : "<<profit<<endl;
}
};
int BST::count=0;
float BST::sum=0;
int BST::index=0;
int BST::cash=0;
int BST::card=0;
int BST::profit=0;
void read_record(BST &rt)
{
  
    // File pointer
    fstream fin;
    // Open an existing file
    fin.open("yellow_tripdata_2016-01.csv", ios::in);
    if(fin==NULL)
    {
    cout<<"File not found\n";
  	exit(0);
	}
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;
    getline(fin,line);
    while (!fin.eof())
	 {
	 	getline(fin, line);
        row.clear();
        // read an entire row and
        // store it in a string variable 'line'
        
  
        // used for breaking words
        stringstream s(line);
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
		
		if(fin.eof())
        {
        	fin.close();
        	break;
		}
		int vid=stoi(row[0]);
		string pickupDateTime = row[1];
		string dropoffDateTime = row[2];
		stringstream l(pickupDateTime);
		vector<string> dateTime;
		while (getline(l, word, ' ')) {
            // add all the column data
            // of a row to a vector
          dateTime.push_back(word);
        }
        stringstream k(dropoffDateTime);
		while (getline(k, word, ' ')) {
            // add all the column data
            // of a row to a vector
          dateTime.push_back(word);
        }
        double lat = stof(row[10]);
        double lon = stof(row[9]);
		int passCount=stoi(row[3]);
		float distance=stof(row[4]);
		int paytype=stoi(row[11]);
		float total_amount=stof(row[18]);
		string pdate = dateTime[0];
		string ptime = dateTime[1];
		string ddate = dateTime[2];
		string dtime = dateTime[3];
		if(passCount<=4 && lat!=0 && lon!=0){
		rt.insertNode(total_amount,passCount,ptime,dtime,distance,paytype,lat,lon);
		}
        if(fin.eof())
        {
        	fin.close();
        	break;
		}
	}
	fin.close();
}

int main(){
	BST tree;
	int choice=0;
	read_record(tree);
	string ptime,dtime,word;
	do{
	system("cls");
	cout<<"1. Enter Pickup and Dropoff Time and see expected Trip cost"<<endl<<endl<<"2. Top 10 Cheapest Trips"<<endl<<endl<<"3. Top 10 Cheapest Trips including Discounted trips"<<endl<<endl;
	cout<<"4. Co-ordinates of most  visited location"<<endl<<endl;
	cout<<"5. Number of current Non-Subscribers and Subscribers"<<endl<<endl;
	cout<<"6. Company's Profit"<<endl<<endl;
	cout<<"Enter Choice: ";
	cin>>choice;
	switch(choice){
	system("cls");
	case 1:{
		
	system("cls");
	lab:
	cout<<"Enter Pickup Time(0:00): ";
	cin>>ptime;
	cout<<"Enter Dropoff Time(0:00): ";
	cin>>dtime;
		for(int i=0;i<ptime.size();i++){
	if(ptime[i]<48||ptime[i]>58||dtime[i]<48||dtime[i]>58){
		cout<<"Invalid Input.Enter Again"<<endl;
		goto lab;
	}
	
	}
	vector<string> v1;
	stringstream s(ptime);
	while(getline(s,word,':')){
		v1.push_back(word);
	}

	stringstream l(dtime);
	while(getline(l,word,':')){
		    v1.push_back(word);
	        }
	        int phour = stoi(v1[0]);
	        int pmin = stoi(v1[1]);
	        int dhour = stoi(v1[2]);
	        int dmin = stoi(v1[3]);
	        if(phour>23 || dhour > 23 || pmin>59 || dmin>59 ){
	         cout<<"Invalid Input.Enter Again"<<endl;
		     goto lab;
			}
	        tree.inorder(tree.root,phour,pmin,dhour,dmin);
	        cout<<"Total number of rides in this timeframe : "<<tree.count<<endl;
	        cout<<"Average ride cost during this timeframe : "<<tree.sum/tree.count<<endl;
	        int pf = (tree.sum/tree.count);
	        pf = pf%3;
	        if(pf == 0){
            pf = 1;
	        }
	        cout<<"Peak Factor : "<<pf<<endl;
	        cout<<"Expected Price For Trip : "<<(tree.sum/tree.count)*pf<<endl;
	        cout<<endl<<"Press Enter to go back to main menu"<<endl;
	        getch();
			break;
			}
			case 2:{
				system("cls");
				tree.index=0;
				cout<<"Total Fare   Pickup Time   Dropoff Time"<<endl;
				tree.inorder1(tree.root);
				cout<<endl<<"Press Enter to go back to main menu"<<endl;
				getch();
				break;
			}
			case 3:{
				system("cls");
				tree.index=0;
				cout<<"Discounted Rides"<<endl;
				cout<<"Total Fare    Pickup Time    Dropoff Time"<<endl;
				tree.inorder2(tree.root);
				cout<<endl<<"Press Enter to go back to main menu"<<endl;
				getch();
				break;
			}
			case 4:{
				system("cls");
				cout<<fixed<<setprecision(2);
				linkedlist l1;
				tree.createlist(tree.root,l1);
				cout<<"List Created "<<endl;
				l1.checkMax();
			    cout<<endl<<"Press Enter to go back to main menu"<<endl;
				getch();
				break;
			}
			case 5:{
				system("cls");
				tree.card=0;
				tree.cash=0;
				tree.inorder3(tree.root);
				cout<<"Number of Non-Subscribers :"<< tree.cash<<endl;
				cout<<"Number of Subscribers :"<< tree.card<<endl;
				cout<<endl<<"Press Enter to go back to main menu"<<endl;
				getch();
				break;
			}
			case 6:{
				system("cls");
				tree.companyProfit();
				cout<<endl<<"Press Enter to go back to main menu"<<endl;
				getch();
				break;
			}
		}
		
	}while(choice!=-1);

		
}
