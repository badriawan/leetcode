#include<iostream>
#include<iomanip>

using namespace std;


struct JointNode{
    int id;
    double angle;
    double torque;
    JointNode* next;
};

void addJoint(JointNode*& head,int id,double angle,double torque){
    JointNode* newjoint = new JointNode{id,angle,torque,nullptr};

    if(head == nullptr){
        head = newjoint;
    }
    else{
        JointNode* temp = head; //pointer disini tidak pakai new karena merujuk pada nilai pointernya bukan variable reference
        while(temp->next != nullptr){
            temp = temp->next; 
        }
        temp->next = newjoint; 

    }

}


void removeJoint(JointNode*& head,int id){
    if (head == nullptr){
        cout<<"empty linked list"<<endl;
        return;
    }

    if(head->id == id){
        JointNode* temp = head;
        head = head->next;
        delete temp;
        cout<<"success removed"<<endl;
        return;

    }


}

void displayJoint(JointNode*& head){
    if (head == nullptr){
        cout<<"empty linked list"<<endl;
        return;
    }

    JointNode* temp = head
    while(temp != nullptr){
        cout<< left << setw(10) << "ID" << temp->id<<endl;
        temp = temp->next;

    }






}

int main(){
    JointNode* head = nullptr;

    addJoint(head,1,45,100);
    cout << "Data Joint setelah penambahan:\n";
    displayJoint(head);

    return 0;




}