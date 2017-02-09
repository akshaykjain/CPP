class Sorter
{
public:
    Sorter();
    void makeEmpty();
    bool isFull() const;
    int getLength() const;
    void insertData(int value);
    void removeData(int value);
    void display();
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void mergeSort();
    void quickSort();
    void heapsort();
private:
    void m_sort(int num[], int n);
    void merge(int left[], int right[], int num[], int nL, int nR);
    void q_sort(int num[], int start, int end);
    int q_sortPartition(int num[], int start, int end);
    void heapify(int arr[], int l, int i);
    int length;
    int arr[10];
};