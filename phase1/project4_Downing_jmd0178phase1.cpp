#include <string>
#include <iostream>

using namespace std;


//Base Claqss
class QuestionNode {
public:
    string type;
    string questionPrompt; 
    int ptValue;
    QuestionNode* prevQuestion;
    QuestionNode* nextQuestion;
    //constructor
    QuestionNode(string type, string questionPrompt, int ptValue);
};
QuestionNode::QuestionNode(string type, string questionPrompt, int ptValue) {
    this->type = type;
    this->questionPrompt = questionPrompt;
    this->ptValue = ptValue;
}
//Child Class
class TF : public QuestionNode {
public:
    //additional properties
    char correctAns;
    //constructor
    TF(string questionPrompt, int ptValue, char correctAns);
};
TF::TF(string questionPrompt, int ptValue, char correctAns)
    : QuestionNode("tf",questionPrompt, ptValue)
    {
    this->correctAns = correctAns;
}

class WR : public QuestionNode {
public:
    //additional properties
    string correctAns;
    //constructor
    WR(string questionPrompt, int ptValue, string correctAns);
};
WR::WR(string questionPrompt, int ptValue, string correctAns)
    : QuestionNode("wf",questionPrompt, ptValue)
    {
    this->correctAns = correctAns;
}

class MC : public QuestionNode {
public:
    //additional properties
    char correctAns;
    
    //constructor
    MC(string questionPrompt, int ptValue, char correctAns);
};

MC::MC(string questionPrompt, int ptValue, char correctAns)
    : QuestionNode("mcq",questionPrompt, ptValue)
    {
    this->correctAns = correctAns;
}

void printForward(QuestionNode* startingNode) {
    QuestionNode* traverser = startingNode;
    while (traverser != nullptr) {
        cout << traverser -> ptValue << endl;
        traverser = traverser -> nextQuestion;
    }
}

/**
 * @brief Get the Node object position places away from head (inclusive)
 * 
 * @param head            start of the doubly linked list
 * @param position        how many nodes after the head to find (including head)
 * @return currentNode    returns pointer to located QuestionNode 
 */
QuestionNode* getNode(QuestionNode* head, int position) {
    //TODO:verify int position
    
    QuestionNode* currentNode = head;
    int i = 1;

    while (currentNode != nullptr && i < position) {
        currentNode = currentNode->nextQuestion;
        i++;
    }
    return currentNode;
}


/**
 * @brief DECOMISSIONED- Adds pointer Node after chosen node
 * 
 * @param newNode       Node to be added
 * @param appendedTo    Node that is appended to
 * @param tail          last Node in doubly linked list
 */
/* void addNodeAfter(QuestionNode* newNode, QuestionNode* &appendedTo, QuestionNode* &tail ) {
    //check if appendTo is tail
    if (appendedTo->nextQuestion == nullptr) {
        //append and update tail
        newNode->prevQuestion = appendedTo;
        newNode->nextQuestion = nullptr;
        appendedTo->nextQuestion = newNode;  
        tail = newNode;
    } else {//otherwise must newNode is between two nodes
        appendedTo->nextQuestion->prevQuestion= newNode;
        newNode->nextQuestion = appendedTo->nextQuestion;
        newNode->prevQuestion = appendedTo;
        appendedTo->nextQuestion = newNode;
    }
} */


void appendToTail(QuestionNode* newNode, QuestionNode* &tail) {
    newNode->prevQuestion = tail;
    newNode->nextQuestion = nullptr;
    tail->nextQuestion = newNode;  
    tail = newNode;
}
int main() {
    //initialize head and tail properties
    QuestionNode* head;

    QuestionNode* tail;

    //add 1st node
    QuestionNode* initNode = new QuestionNode("tf", "",0);
    initNode->ptValue = 0;
    initNode-> nextQuestion= nullptr;
    initNode->prevQuestion= nullptr;
    head = initNode;
    tail = initNode;

    QuestionNode* q1 = new QuestionNode("tf", "?", 1);
    appendToTail(q1 ,tail); 
    QuestionNode* q2 = new QuestionNode("tf", "?", 2);
    appendToTail(q2 ,tail);

    TF* t1 = new TF("is this true", 12, 't');
    appendToTail(t1, tail);

    WR* w1 = new WR("tell about ..", 15, "no");
    appendToTail(w1, tail);

    /* QuestionNode* tempNode = getNode(head,2);
    addNodeAfter(q5, tempNode, tail);  */

    

    
    printForward(head);
    
    cout <<endl<< getNode(head, 3)->ptValue << endl; 
    cout << getNode(head, 2)->ptValue << endl; 
    cout << getNode(head, 1)->ptValue << endl; 
    return 0;
}