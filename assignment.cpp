#include<iostream>
#include<ctype.h>
#include<iomanip>

using namespace std;
int PLAN = 0;
int CUSTOMER  = 0;
int POSITION = 0;

class TrainingPlan{
    string name;
    int sessionsPerWeek;
    float feesPerWeek;
    float feesPerMonth;
    public:
        TrainingPlan(){
            name = "";
            sessionsPerWeek = 0;
            feesPerMonth = 0;
            feesPerWeek = 0;
        }
        TrainingPlan(string n, int s, float FPW, float FPM){
            name = n;
            sessionsPerWeek = s;
            feesPerWeek = FPW;
            feesPerMonth = FPM;
            PLAN++;
        }
        void setPlan(){
            cout<<"Add the plan name : ";
            cin.get();
            getline(cin, name);
            cout<<"Add the event per week : ";
            cin>>sessionsPerWeek;
            feeLabel:
            cout<<"Add the fees per week(enter 0 if you consider adding fees per month) : ";
            cin>>feesPerWeek;
            cout<<"Add the fees per month(enter 0 if fees per week is already inputted) : ";
            cin>>feesPerMonth;
            if(feesPerMonth > 0 && feesPerWeek > 0) {
                cout<<"Your feedback two numbers greater than 0.\n";
                cin.get();
                goto feeLabel;
            }
            cout<<"Successfully built a training plan.("<<name<<")!\n";
            cin.get();
            PLAN++;
        }
        void EditPlan(){
            cout<<"Plan name("<<name<<") : \n";
            cout<<"Add the sessions per week ("<<sessionsPerWeek<<") : ";
            cin>>sessionsPerWeek;
            feeLabel:
            cout<<"Enter fees per week ("<<feesPerWeek<<") : ";
            cin>>feesPerWeek;
            cout<<"Enter fees per month ("<<feesPerMonth<<") : ";
            cin>>feesPerMonth;
            if(feesPerMonth > 0 && feesPerWeek > 0) {
                cout<<"You entered both values greather than 0.\n";
                cin.get();
                goto feeLabel;
            }
            cout<<"Successfully updated the training plan("<<name<<")!\n";
            cin.get();
        } 
        string getPlanName() {return name;}
        float getFeesPerWeek() {return feesPerWeek;}
        float getFeesPerMonth() {return feesPerMonth;}
        int getSessionsPerWeek() {return sessionsPerWeek;}
        void displayPlan(){
            cout<<setw(20)<<name
                <<setw(20)<<sessionsPerWeek
                <<setw(15)<<feesPerWeek
                <<setw(15)<<feesPerMonth;
        }
};
class Customer{
    string name;
    TrainingPlan trainingPlan;
    float weight;
    string learntPoses[10];
    int learntPosesCount;
    int privateHours[4];
    bool privateHourOnlineOffline[4];
    float cost;
    public:
        Customer(){
            name = "";
            weight = 0;
            cost = 0;
            learntPosesCount = 0;
            for(int i=0; i<4; i++){
                privateHours[i] = 0;
                privateHourOnlineOffline[i] = 0;
            }
        }
        Customer(string n, TrainingPlan tp, float w, int h[4], bool OnOff[4]){
            name = n;
            trainingPlan = tp;
            weight = w;
            cost = 0;
            for(int i=0; i<4; i++){
                privateHours[i] = h[i];
                privateHourOnlineOffline[i] = OnOff[i];
            }
            CUSTOMER++;
        }
        string setCustomer(TrainingPlan plans[]){
            int planIndex = 0;
            cout<<"Add the customer name : ";
            cin.get();
            getline(cin, name);

            trainingPlanLabel:
            cout<<"Enter training plan - Available plans : \n";
            for(int i=0; i<PLAN; i++){
                cout<<"Plan : "<<i+1<<" "<<plans[i].getPlanName();
                if(i+1!=PLAN) cout<<" ,\n";
            }
            cout<<"\nChoose the index : ";
            if(planIndex < 0 || planIndex > PLAN) goto trainingPlanLabel;
            cin>>planIndex;
            trainingPlan = plans[planIndex-1];

            cout<<"Enter current weight : ";
            cin>>weight;

            for(int i=0; i<4; i++){
                char o = '0';
                privateHourLabel:
                cout<<"Enter"<<i+1<<" th/st week private hours : \n";
                cin>>privateHours[i];
                if(privateHours[i] < 0 || privateHours[i] > 5) {
                    cout<<"It exceeded 5 or less than 0\n";
                    goto privateHourLabel;
                }
                
                onlineOfflineLabel:
                cout<<"Online/Offline(0/1) : ";
                cin>>o;
                if(o!='0'||o!='1') goto onlineOfflineLabel;
                if(o=='0') privateHourOnlineOffline[i] = 0;
                else privateHourOnlineOffline[i] = 1;
            }
            CUSTOMER++;
            return trainingPlan.getPlanName();
        }
        string updateCustomer(TrainingPlan plans[]){
            int planIndex = 0;
            cout<<"Customer name("<<name<<") : \n";

            trainingPlanLabel:
            cout<<"Enter training plan - Available plans : \n";
            for(int i=0; i<PLAN; i++){
                cout<<"Plan : "<<i+1<<" "<<plans[i].getPlanName();
                if(i+1!=PLAN) cout<<" ,\n";
            }
            cout<<"\nChoose the index : ";
            if(planIndex < 0 || planIndex > PLAN) goto trainingPlanLabel;
            cin>>planIndex;
            trainingPlan = plans[planIndex-1];

            cout<<"Enter current weight(kg) : ";
            cin>>weight;

            for(int i=0; i<4; i++){
                char o = '0';
                cout<<"Enter"<<i+1<<" th/st week private hours : \n";
                cin>>privateHours[i];
                onlineOfflineLabel:
                cout<<"Online/Offline(0/1) : ";
                cin>>o;
                if(o!='0'||o!='1') goto onlineOfflineLabel;
                if(o=='0') privateHourOnlineOffline[i] = 0;
                else privateHourOnlineOffline[i] = 1;
            }
            return trainingPlan.getPlanName();
        }
        void displayPoses(){
            cout<<setw(30)<<"Learnin poses : ";
            for(int i=0; i<learntPosesCount; i++){
                cout<<learntPoses[i];
                if(i+1!=learntPosesCount) cout<<" ,";
            }
        }
        void addLearntPoses(string poses[]){
            char learnt = 'y';
            int ind = 0;
            int learntInd = 0;
            cout<<"Already learnt poses? (y/n) : ";
            cin>>learnt;
            if(learnt=='y') {
                for(unsigned int i=0; i<poses->length(); i++){
                    cout<<"("<<i+1<<")"<<poses[i];
                    if(i+1 != poses->length()) cout<<" , ";
                }
                while(true){
                    char more = 'y';
                    cout<<"\nEnter pose index : ";
                    cin>>ind;
                    cout<<"Got more?(y/n) : ";
                    cin>>more;
                    learntPosesCount++;
                    learntPoses[learntInd] = poses[ind-1];
                    learntInd++;
                    if(more!='y') break;
                }
            }
            cout<<endl;
        }
        float getFinalCost(){
            int count = learntPosesCount;
            if(learntPosesCount >= 5) count = 5;
            cost = 0;
            if(trainingPlan.getFeesPerMonth()!=0) cost += trainingPlan.getFeesPerMonth();
            else cost += trainingPlan.getFeesPerWeek()*4;
            
            for(int i=0; i<4; i++){
                if(privateHourOnlineOffline[i]) cost += 15000*privateHours[i];
                else cost += 17000*privateHours[i];
            }
            return cost - (cost*count)/100;
        }
        float getCost() {
            cost = 0;
            if(trainingPlan.getFeesPerMonth()!=0) cost += trainingPlan.getFeesPerMonth();
            else cost += trainingPlan.getFeesPerWeek()*4;
            
            for(int i=0; i<4; i++){
                if(privateHourOnlineOffline[i]) cost += 15000*privateHours[i];
                else cost += 17000*privateHours[i];
            }
            return cost;
        }
        void displayCustomer(){
            cout<<setw(20)<<name
                <<setw(20)<<trainingPlan.getPlanName()
                <<setw(10)<<learntPosesCount
                <<setw(20)<<getFinalCost();
        }
        void displayCustomerDetails(){
            int count = learntPosesCount;
            if(learntPosesCount >= 5) count = 5;
            int online = 0, offline = 0;
            for(int i=0; i<4; i++){
                if(privateHourOnlineOffline[i]) online++;
                else offline++;
            }
            cout<<setw(30)<<"Customer name : "<<setw(20)<<name<<endl
                <<setw(30)<<"Weight : "<<setw(20)<<weight<<endl
                <<setw(30)<<"Training plan : "<<setw(20)<<trainingPlan.getPlanName()<<endl;
            displayPoses();
            cout<<endl;

            cout<<setw(30)<<"Sessions per week : "<<setw(20)<<trainingPlan.getSessionsPerWeek();
            if(trainingPlan.getFeesPerMonth()!=0) {
                cout<<setw(20)<<trainingPlan.getFeesPerMonth();
            }
            else {
                cout<<setw(20)<<trainingPlan.getFeesPerWeek()*4;
            }
            cout<<endl;
            cout<<setw(30)<<"Private (Online-15000) : "<<setw(20)<<online<<setw(20)<<15000*online<<endl
                <<setw(30)<<"Private (Offline-17000) : "<<setw(20)<<offline<<setw(20)<<17000*offline<<endl
                <<setw(30)<<"DISCOUNT (%) : "<<setw(20)<<count<<setw(20)<<getCost()*count/100<<endl
                <<setw(30)<<"Total Cost : "<<setw(20)<<""<<setw(20)<<getFinalCost()<<endl;
            cin.get();
        }
};
class Position{
    string name;
    int poseCount;
    public:
    public:
        string poseType[10];
        string poseName[10];
        Position(){
            name = "";
            poseCount = 0;
        }
        Position(string name, string type[10], string names[10]){
            name = name;
            for(int i=0; i<10; i++){
                poseType[i] = type[i];
                poseName[i] = names[i];
                poseCount++;
            }
            POSITION++;
        }
        void addPosition(){
            cout<<"Post name : "<<name<<endl;
            cout<<"Post : ";
            for(int i=0; i<poseCount; i++) {
                cout<<poseName[i];
                if(i+1 != poseCount) cout<<" , ";
                else cout<<endl;
            }
            if(poseCount == 10) {
                cout<<"10 poses already added\n";
                cin.get();
                return;
            }
            char more = 'y';
            while(true){
                if(poseCount==10) break;

                cout<<"Enter post name("<<poseCount+1<<") : ";
                cin.get();
                getline(cin,poseName[poseCount]);
                cout<<"Enter position type("<<poseCount+1<<") : ";
                getline(cin,poseType[poseCount]);
                cout<<"Successfully added("<<poseName[poseCount]<<")\n";
                poseCount++;

                moreLabel:
                cout<<"Add more?(y/n) : ";
                cin>>more;
                if(more=='n') break;
                if(more!='n'||more!='y') goto moreLabel;
            }
        }
        void createPosition(){
            cout<<"Enter position name : ";
            cin.get();
            getline(cin,name);
            addPosition();
        }
        void displayPosition(){
            cout<<setw(20)<<name<<endl;
            for(int i=0; i<poseCount; i++){
                cout<<setw(25)<<""
                    <<setw(20)<<poseType[i]
                    <<setw(20)<<poseName[i]
                    <<endl;
            }
        }
};
void showTrainingPlans(TrainingPlan plans[]);
void showYogaPositions(Position poses[]);
void showCustomers(Customer customers[]);

int main(){
    int menuCode;
    
    Position poses[5];
    string basicPoseType[10] = {"Standing Pose","Standing Pose","Standing Pose","Standing Pose","Balancing Pose","Balancing Pose","Balancing Pose","Balancing Pose","Seat Pose","Backend Pose"};
    string basicPoseNames[10] ={"Archer Pose","Dolphin Pose","Frog Pose","Fallen Triangle","Big Toe Pose","Lion Pose","Airplane Pose","Side Lunge","Side Reclining","Bird Dog Pose"};
    Position pose1("BASIC",basicPoseType,basicPoseNames);
    
    string imPoseType[10] = {"Standing Pose","Standing Pose","Standing Pose","Standing Pose","Balancing Pose","Balancing Pose","Balancing Pose","Balancing Pose","Seat Pose","Backend Pose"};
    string imPoseNames[10] ={"Downward Facing Pose","Mountain Pose","Warrior Pose","Traingle Triangle","Low Lunge","Tree Pose","Plank Pose","Bridge Lunge","Staff Pose","Cobbler's Pose"};
    Position pose2("INTERMEDIATE",imPoseType,imPoseNames);
    
    poses[0] = pose1;
    poses[1] = pose2;
    
    TrainingPlan plans[7];
    TrainingPlan basic("BASIC",3,25000,0);
    TrainingPlan inter("INTERMEDIATE",3,35000,0);
    TrainingPlan advan("ADVANCED",2,50000,0);
    TrainingPlan basicMonth("BASIC",3,0,95000);
    plans[0] = basic;
    plans[1] = inter;
    plans[2] = advan;
    plans[3] = basicMonth;

    Customer customers[50];
    int c1Private[4] = {1,1,3,2};
    bool c1OnOff[4] = {false,false,true,true};
    int c2Private[4] = {1,1,3,2};
    bool c2OnOff[4] = {true,false,true,false};
    int c3Private[4] = {1,1,3,2};
    bool c3OnOff[4] = {true,true,true,true};
    int c4Private[4] = {1,1,3,2};
    bool c4OnOff[4] = {true,false,true,true};
    int c5Private[4] = {1,1,3,2};
    bool c5OnOff[4] = {true,false,false,true};
    
    Customer c1("Zayar Lin Htet",plans[0],55,c1Private,c1OnOff);
    Customer c2("Zayar Lin Htet",plans[0],55,c2Private,c2OnOff);
    Customer c3("Zayar Lin Htet",plans[0],55,c3Private,c3OnOff);
    Customer c4("Zayar Lin Htet",plans[1],55,c4Private,c4OnOff);
    Customer c5("Zayar Lin Htet",plans[2],55,c5Private,c5OnOff);
    customers[0] = c1;
    customers[1] = c2;
    customers[2] = c3;
    customers[3] = c4;
    customers[4] = c5;

    menuLabel:
    cout<<"Welcome from the Amazing Sport Yoga System!"
        <<"\n1. Training plan menu.\n2. Yoga poses menu\n3. Customers menu\n0. Exit the program.\n";
    cin>>menuCode;
    if(menuCode==1) {
        trainingPlanScreenLabel:
        int trainingMenuCode = 0;
        cout<<"1. Add a training plan.\n2. Show all training plans."
            <<"\n3. Update a training plan.\n0. Return to main menu.\n";
        cin>>trainingMenuCode;
      
        if(trainingMenuCode < 0 || trainingMenuCode > 3) goto trainingPlanScreenLabel;
        if(trainingMenuCode == 0) goto menuLabel;
        else if(trainingMenuCode == 1) plans[PLAN].setPlan();
        else if(trainingMenuCode == 2) showTrainingPlans(plans);
        else if(trainingMenuCode == 3) {
            int index = 0;
            showTrainingPlans(plans);
            cout<<"Enter number to update : ";
            cin>>index;
            plans[index-1].EditPlan();
        }
        goto trainingPlanScreenLabel;
    } 
    else if(menuCode==2){
        yogaPoseScreenLabel:
        int yogaScreenCode = 0;
        cout<<"1. Add a yoga plan.\n2. Display yoga plans.\n3. Add yoga poses.\n0. Return to main menu.\n";
        cin>>yogaScreenCode;
        if(yogaScreenCode < 0 || yogaScreenCode > 3) goto yogaPoseScreenLabel;
      
        if(yogaScreenCode == 0) goto menuLabel;
        else if(yogaScreenCode == 1) poses[POSITION].createPosition();
        else if(yogaScreenCode == 2) showYogaPositions(poses);
        else if(yogaScreenCode == 3) {
            int index = 0;
            showYogaPositions(poses);
            cout<<"\nEnter yoga plan index to add : ";
            cin>>index;
            poses[index-1].addPosition();
        }
        goto yogaPoseScreenLabel;
    }
    else if(menuCode==3){
        customerScreenLabel:
        int customerScreenCode = 0;
        cout<<"1. Join a new customer..\n2. View all customers."
            <<"\n3. Update customer info.\n4. Calculate costs for the customer.\n0. Return to main menu. \n";
        cin>>customerScreenCode;
        if(customerScreenCode < 0 || customerScreenCode > 4) goto customerScreenLabel;
      
        if(customerScreenCode == 0) goto menuLabel;
        else if(customerScreenCode == 1) {
            string planName = customers[CUSTOMER].setCustomer(plans);
            if(planName == "INTERMEDIATE") customers[CUSTOMER-1].addLearntPoses(poses[0].poseName);
            else if(planName == "ADVANCED") customers[CUSTOMER-1].addLearntPoses(poses[1].poseName);
            customers[CUSTOMER-1].displayCustomerDetails();
        }
        else if(customerScreenCode == 2) showCustomers(customers);
        else if(customerScreenCode == 3) {
            int index = 0;
            showCustomers(customers);
            cout<<"Enter number to update : ";
            cin>>index;
            customers[index-1].updateCustomer(plans);
        }
        else if(customerScreenCode == 4) {
            int index = 0;
            showCustomers(customers);
            cout<<"Enter number to calculate costs : ";
            cin>>index;
            customers[index-1].displayCustomerDetails();
        }
        goto customerScreenLabel;
    }
    else if(menuCode==0) return 0;
    else goto menuLabel;
}

void showTrainingPlans(TrainingPlan plans[]){
    cout<<setw(5)<<"No"
        <<setw(20)<<"Plan name"
        <<setw(20)<<"event per week"
        <<setw(15)<<"Fees per week"
        <<setw(15)<<"Fees per month"
        <<endl;
    for(int i=0; i<PLAN; i++) {
        cout<<setw(5)<<i+1;
        plans[i].displayPlan();
        cout<<endl;
    }
}

void showYogaPositions(Position poses[]){
    cout<<setw(5)<<"No"
        <<setw(20)<<"Post names"
        <<setw(20)<<"Pose type"
        <<setw(20)<<"Pose name"
        <<endl;
    for(int i=0; i<POSITION; i++) {
        cout<<setw(5)<<i+1;
        poses[i].displayPosition();
        cout<<endl;
    }
}

void showCustomers(Customer customers[]){
    cout<<setw(5)<<"No"
        <<setw(20)<<"Customer name"
        <<setw(20)<<"Training plan"
        <<setw(10)<<"Learnt poses count"
        <<setw(20)<<"Cost(current month)"
        <<endl;
    for(int i=0; i<CUSTOMER; i++) {
        cout<<setw(5)<<i+1;
        customers[i].displayCustomer();
        cout<<endl;
    }
}