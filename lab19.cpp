#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <vector>

using namespace std;

struct ReviewNode {
    float rating; // Movie rating
    string comments; // Review comments
    ReviewNode* next; // Pointer to the next node
};

class Movie {
private:
    string title; // Movie title
    ReviewNode* ratingsHead; // Head of the ratings linked list
    ReviewNode* commentsHead; // Head of the comments linked list

public:
    Movie(string t) : title(t), ratingsHead(nullptr), commentsHead(nullptr) {}
    
    void addReview(float rating, const string& comment);
    void outputReviews() const;
    float calculateAverage() const;
    ~Movie(); // Destructor to clean up linked lists
};

void Movie::addReview(float rating, const string& comment) {
    // Create a new ReviewNode
    ReviewNode* newReview = new ReviewNode;
    newReview->rating = rating;
    newReview->comments = comment;
    newReview->next = nullptr;

    // Add to ratings list
    if (!ratingsHead) {
        ratingsHead = newReview;
    } else {
        ReviewNode* current = ratingsHead;
        while (current->next) {
            current = current->next;
        }
        current->next = newReview; // Link new node at the end
    }

    // Add to comments list
    ReviewNode* commentNode = new ReviewNode;
    commentNode->rating = rating; // Rating goes in the comments list too
    commentNode->comments = comment;
    commentNode->next = nullptr;

    if (!commentsHead) {
        commentsHead = commentNode;
    } else {
        ReviewNode* current = commentsHead;
        while (current->next) {
            current = current->next;
        }
        current->next = commentNode; // Link new comment node at the end
    }
}

void Movie::outputReviews() const {
    if (!ratingsHead) {
        cout << "No reviews available for " << title << "." << endl;
        return;
    }
    
    cout << "Outputting all reviews for " << title << ":" << endl;
    ReviewNode* current = ratingsHead;
    int count = 1;
    while (current) {
        cout << "    > Review #" << count++ << ": " << current->rating << ": " << current->comments << endl;
        current = current->next;
    }
}

float Movie::calculateAverage() const {
    if (!ratingsHead) return 0.0;

    float sum = 0.0;
    int count = 0;
    ReviewNode* current = ratingsHead;

    while (current) {
        sum += current->rating; // Accumulate the ratings
        count++;
        current = current->next;
    }
    
    return sum / count; // Return average
}

Movie::~Movie() {
    // Clean up linked lists for ratings and comments
    ReviewNode* current = ratingsHead;
    while (current) {
        ReviewNode* temp = current;
        current = current->next;
        delete temp; // Delete the current node
    }
    ratingsHead = nullptr; // Set head to nullptr
}

void loadReviewsFromFile(Movie& movie, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open the file: " << filename << endl;
        return;
    }

    string comment;
    while (getline(file, comment)) {
        // Generate a random rating between 1.0 and 5.0
        float rating = (rand() % 41 + 10) / 10.0; // Generates a rating from 1.0 to 5.0
        movie.addReview(rating, comment);
    }

    file.close();
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    vector<Movie> movies; // Container for movies
    movies.push_back(Movie("Movie A"));
    movies.push_back(Movie("Movie B"));

    // Load reviews from external file for Movie A
    loadReviewsFromFile(movies[0], "reviews_movie_a.txt");
    // Load reviews from external file for Movie B
    loadReviewsFromFile(movies[1], "reviews_movie_b.txt");

    // Output reviews and averages
    for (const Movie& movie : movies) {
        movie.outputReviews();
        cout << "> Average: " << setprecision(5) << movie.calculateAverage() << endl;
    }

    return 0;
}
