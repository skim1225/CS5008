#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool binarySearch(const vector <int>& nums, int num, int left, int right);

int main()
{
    vector <int> nums = {2, 4, 5, 10, 22, 30, 45, 51, 62, 100};
    cout << "My vector: " << endl;
    vector<int>::iterator itr;
    for (itr = nums.begin(); itr != nums.end(); ++itr) {
        cout << " " << *itr << " ";
    }
    cout << endl;
    cout << "Enter a number to search: ";
    int num;
    cin >> num;
    cout << endl;
    bool contains = binarySearch(nums, num, 0, nums.size() - 1);
    if (contains) {
        cout << "The vector contains " << num << endl;
    }
    else {
        cout << "The vector does not contain " << num << endl;
    }
    return 0;
}

bool binarySearch(const vector <int> &nums, int num, int left, int right) {

    if (left > right)
        return false;;
    int mid = left + (right - left) / 2;
    if (nums[mid] == num)
        return true;
    if (nums[mid] > num) {
        return binarySearch(nums, num, left, mid - 1);
    } 
    else {
        return binarySearch(nums, num, mid + 1, right);
    }
}