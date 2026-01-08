#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define d 256 // number of characters in the input alphabet
#define q 101 // a prime number

// Rabin-Karp Algorithm
void robinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        cout << "Pattern is longer than text. No match possible.\n";
        return;
    }

    int p = 0; // hash for pattern
    int t = 0; // hash for text window
    int h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    cout << "\nPattern hash value: " << p << "\n";
    cout << "Starting search...\n\n";

    for (int i = 0; i <= n - m; i++) {
        cout << "Checking at position " << i << " --> Window: " << text.substr(i, m)
             << " --> Hash: " << t;

        if (p == t) {
            bool found = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << " --> Found at Index: " << i << "\n";
            } else {
                cout << " --> False Match\n";
            }
        } else {
            cout << " --> No Match\n";
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

// Naive Pattern Matching
void naiveMatchingFunction(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    for (int i = 0; i <= n - m; i++) {
        cout << "Checking at position " << i << ": ";
        string current = text.substr(i, m);
        cout << current << "\n";

        if (current == pattern) {
            cout << "Pattern Found\n";
            found = true;
        } else {
            cout << "Not found.\n";
        }
    }

    if (!found) {
        cout << "Pattern not found anywhere in the text.\n";
    }
}

// Linear Search Visualizer
void linearSearchVisualizer(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "Checking index " << i << ": " << arr[i] << endl;
        if (arr[i] == target) {
            cout << "Target Found at index " << i << "!" << endl;
            return;
        }
    }
    cout << "Target not found." << endl;
}

// Binary Search Visualizer
void binarySearchVisualizer(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        cout << "Middle element: " << arr[mid] << endl;
        if (arr[mid] == target) {
            cout << "Target Found!" << endl;
            return;
        } else if (arr[mid] < target) {
            cout << "Go Right" << endl;
            left = mid + 1;
        } else {
            cout << "Go Left" << endl;
            right = mid - 1;
        }
    }
    cout << "Target not found." << endl;
}

void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}
//Insertion sort
void insertionSort(vector<int> arr) {
    cout << "\n--- Insertion Sort ---\n";
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        cout << "\nPass " << i << ": Inserting " << key << endl;
        while (j >= 0 && arr[j] > key) {
            cout << "Swap " << arr[j] << " and " << arr[j + 1] << endl;
            arr[j + 1] = arr[j];
            printArray(arr);
            j--;
        }
        arr[j + 1] = key;
        printArray(arr);
    }
}
//merge sort
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);

    cout << "\nMerging ";
    printArray(L);
    cout << "with ";
    printArray(R);

    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];

    cout << "Merged: ";
    printArray(vector<int>(arr.begin() + l, arr.begin() + r + 1));
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    cout << "\nPivot: " << pivot << endl;

    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            cout << "Swapped " << arr[i] << " and " << arr[j] << " -> ";
            printArray(arr);
        }
    }
    swap(arr[i + 1], arr[high]);
    cout << "Swapped pivot " << arr[i + 1] << " and " << arr[high] << " -> ";
    printArray(arr);
    return i + 1;
}
//QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//Bubble sort
void bubbleSortWithSteps(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        cout << "\n--- Pass " << i + 1 << " ---\n";

        for (int j = 0; j < n - i - 1; j++) {
            cout << "Comparing [" << arr[j] << "] and [" << arr[j+1] << "]: ";

            if (arr[j] > arr[j + 1]) {
                cout << "Swapping (" << arr[j] << " <-> " << arr[j+1] << ")\n";
                swap(arr[j], arr[j + 1]);
                swapped = true;
                cout << "Array now: [";
                for (int k = 0; k < n; k++) {
                    cout << arr[k];
                    if (k < n - 1) cout << ", ";
                }
                cout << "]\n";
            } else {
                cout << "No swap needed\n";
            }
        }
        cout << "After Pass " << i + 1 << ": [";
        for (int k = 0; k < n; k++) {
            cout << arr[k];
            if (k < n - 1) cout << ", ";
        }
        cout << "]\n";

        if (!swapped) break;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Algorithm Visualizer ---\n";
        cout << " 1. Search (Linear / Binary)\n";
        cout << " 2. Pattern Matching (Naive / Rabin-Karp)\n";
        cout << " 3. Sorting (Insertion / Merge / Quick / Bubble)\n";
        cout << " 4. Exit\n";
        cout << "Enter choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {                       // Search Option
                int n, target, option;
                vector<int> arr;

                cout << "\n1. Linear Search\n2. Binary Search\n3. Back to Main Menu\nEnter option: ";
                cin >> option;

                if (option == 3) break;

                cout << "Enter number of elements: ";
                cin >> n;
                arr.resize(n);
                cout << "Enter elements:\n";
                for (int i = 0; i < n; ++i) cin >> arr[i];

                cout << "Enter target to search: ";
                cin >> target;

                switch (option) {
                    case 1:
                        linearSearchVisualizer(arr, target);
                        break;
                    case 2:
                        sort(arr.begin(), arr.end());
                        cout << "Sorted array for Binary Search: ";
                        printArray(arr);
                        binarySearchVisualizer(arr, target);
                        break;
                    default:
                        cout << "Invalid search option.\n";
                        break;
                }
                break;
            }

            case 2: {               //Pattern Match
                int opt;
                string text, pattern;
                //cin.ignore();

                cout << "\n1. Naive\n2. Rabin-Karp\n3. Back to Main Menu\nEnter option: ";
                cin >> opt;
                cin.ignore();

                if (opt == 3) break;

                cout << "Enter Text: ";
                getline(cin, text);
                cout << "Enter Pattern: ";
                getline(cin, pattern);

                switch (opt) {
                    case 1:
                        naiveMatchingFunction(text, pattern);
                        break;
                    case 2:
                        robinKarp(text, pattern);
                        break;
                    default:
                        cout << "Invalid pattern matching option.\n";
                        break;
                }
                break;
            }

            case 3: {                               //Sorting
                int n, opt;
                vector<int> arr;

                cout << "\n1. Insertion Sort\n2. Merge Sort\n3. Quick Sort\n4. Bubble Sort\n5. Back to Main Menu\nEnter option: ";
                cin >> opt;

                if (opt == 5) break;

                cout << "Enter number of elements: ";
                cin >> n;
                arr.resize(n);
                cout << "Enter elements:\n";
                for (int i = 0; i < n; ++i) cin >> arr[i];

                vector<int> copy = arr;

                switch (opt) {
                    case 1: insertionSort(copy); break;
                    case 2: mergeSort(copy, 0, n - 1); break;
                    case 3: quickSort(copy, 0, n - 1); break;
                    case 4: bubbleSortWithSteps(copy); break;
                    default: cout << "Invalid sorting option.\n"; break;
                }
                break;
            }

            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid main menu choice.\n";
        }
    }

    return 0;
}