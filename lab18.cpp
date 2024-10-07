#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct ReviewNode {
    float rating;        // Movie rating
    string comments;     // Review comments
    ReviewNode* next;    // Pointer to the next node
};

// Function prototypes
void addReviewToTail(ReviewNode*& head, float rating, string comments);
void outputReviews(ReviewNode* head);
float calculateAverage(ReviewNode* head);
void deleteList(ReviewNode*& head);

int main() {
    ReviewNode* head = nullptr; // Head of the linked list
    int mode;
    char another;

    // User chooses linked list mode
    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "Choice: ";
    cin >> mode;

    do {
        float rating;
        string comments;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore(); // To ignore the newline character left by cin
        cout << "Enter review comments: ";
        getline(cin, comments); // Get entire line for comments

        // Add review to the linked list based on the chosen mode
        if (mode == 1) {
            addReviewToTail(head, rating, comments);
        } else {
            addReviewToTail(head, rating, comments);
        }

        cout << "Enter another review? Y/N: ";
        cin >> another;

    } while (another == 'Y' || another == 'y');

    // Output all reviews and average rating
    outputReviews(head);
    cout << "> Average: " << setprecision(5) << calculateAverage(head) << endl;

    // Clean up linked list
    deleteList(head);

    return 0;
}

void addReviewToTail(ReviewNode*& head, float rating, string comments) {
    ReviewNode* newReview = new ReviewNode; // Create a new node
    newReview->rating = rating;
    newReview->comments = comments;
    newReview->next = nullptr;

    // If the list is empty, the new review becomes the head
    if (!head) {
        head = newReview;
    } else {
        // Otherwise, find the last node
        ReviewNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newReview; // Link new node at the end
    }
}

void outputReviews(ReviewNode* head) {
    if (!head) {
        cout << "No reviews available." << endl;
        return;
    }
    
    cout << "Outputting all reviews:" << endl;
    int count = 1;
    ReviewNode* current = head;
    while (current) {
        cout << "    > Review #" << count++ << ": " << current->rating << ": " << current->comments << endl;
        current = current->next;
    }
}

float calculateAverage(ReviewNode* head) {
    if (!head) return 0.0;

    float sum = 0.0;
    int count = 0;
    ReviewNode* current = head;
    
    while (current) {
        sum += current->rating; // Accumulate the ratings
        count++;
        current = current->next;
    }
    
    return sum / count; // Return average
}

void deleteList(ReviewNode*& head) {
    ReviewNode* current = head;
    while (current) {
        ReviewNode* temp = current;
        current = current->next;
        delete temp; // Delete the current node
    }
    head = nullptr; // Set head to nullptr
}


