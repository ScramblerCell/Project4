#include <string>
#include <iostream>

using namespace std;



class QuestionNode {//base class
public:
    string type;
    string questionPrompt; 
    int ptValue;
    QuestionNode* prevQuestion;
    QuestionNode* nextQuestion;
    //constructor
    QuestionNode(string type, string questionPrompt, int ptValue) {
        this->type = type;
        this->questionPrompt = questionPrompt;
        this->ptValue = ptValue;
    }
};

void printForward(QuestionNode* head) {
    QuestionNode* traverser = head;
    while (traverser != nullptr) {
        cout << traverser -> ptValue << endl;
        traverser = traverser -> nextQuestion;
    }
}

/**
 * @brief Get the Node object position places away from head (inclusive)
 * 
 * @param head 
 * @param position 
 * @return QuestionNode* 
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

void addNodeAfter(QuestionNode* newNode, QuestionNode* &appendedTo, QuestionNode* &tail ) {
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
    addNodeAfter(q1, tail, tail);
    QuestionNode* q2 = new QuestionNode("tf", "??", 2);
    addNodeAfter(q2, tail, tail);
    QuestionNode* q3 = new QuestionNode("tf", "???", 3);
    addNodeAfter(q3, tail, tail);
    QuestionNode* q4 = new QuestionNode("tf", "????", 4);
    addNodeAfter(q4, tail, tail);

    QuestionNode*  q5 = new QuestionNode("tf", "?????", 5);
    /* QuestionNode* tempNode = getNode(head,2);
    addNodeAfter(q5, tempNode, tail);  */
    
    printForward(head);
    
    cout <<endl<< getNode(head, 3)->ptValue << endl; 
    cout << getNode(head, 2)->ptValue << endl; 
    cout << getNode(head, 1)->ptValue << endl; 
    return 0;
}