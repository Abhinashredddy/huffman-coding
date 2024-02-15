#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq, Node* l = NULL, Node* r = NULL)
        : data(data), freq(freq), left(l), right(r) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root)
        return;
    if (root->data != '$')
        cout << str << " ";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffmanCodes(char data[], int freq[], int size) {
    Node *left, *right, *top;
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new Node('$', left->freq + right->freq, left, right);
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main() {
    int size;
    cout << "Enter the number of characters: ";
    cin >> size;

    char arr[size];
    int freq[size];

    cout << "Enter the characters and their frequencies:\n";
    for(int i = 0; i < size; i++) {
        cout << "Character: ";
        cin >> arr[i];
        cout << "Frequency: ";
        cin >> freq[i];
    }

    huffmanCodes(arr, freq, size);
    return 0;
}
