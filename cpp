class Solution {
public:



   vector<ListNode*> splitListToParts(ListNode* head, int k) {
    // Calculate the length of the linked list
    int length = 0;
    ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    // Calculate the size of each part and the remainder
    int partSize = length / k;
    int remainder = length % k;

    std::vector<ListNode*> result;
    current = head;
    for (int i = 0; i < k; i++) {
        result.push_back(current);

        int partLength = partSize + (i < remainder ? 1 : 0); // Distribute remainder
        for (int j = 1; j < partLength; j++) {
            current = current->next;
        }

        if (current) {
            ListNode* nextNode = current->next;
            current->next = nullptr;
            current = nextNode;
        }
    }

    return result;
}

      
};
