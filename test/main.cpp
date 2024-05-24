#include <iostream>
#include <vector>
#include <string.h>
#include <functional>
#include <mutex>
#include <stack>
#include <set>
#include <map>
#include <list>
#define  _CRT_SECURE_NO_WARNINGS
using namespace std;
void sort(int* arr, int len) {
	for (int i = 0; i < len - 1 ; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void sort(vector<int>& arr, std::function<bool(int, int)> f) {
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = 0; j < arr.size() - 1 - i; j++) {
			if (f(arr[j] , arr[j + 1])) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}

}

bool find(int* arr, int len, int number) {
	if (len <= 0) {
		return false;
	}
	int mid = len / 2;
	int left = mid - 1;
	int right = mid + 1;

	if (arr[mid] == number) {
		return true;
	} else if (arr[mid] > number) {
		find(arr, left, number);
	} else {
		find(arr + right, len - left, number);
	}
	return false;
}

class MyString
{
public:
	MyString(char* str){
		if (str == nullptr) {
			buf = new char[1];
			buf[0] = '\0';
			return;
		}
		buf = new char[strlen(str)];
		strcpy(buf, str);
	}
	MyString(const MyString& str) {
		buf = new char[str.len() + 1];
		strcpy(buf, str.c_str());
	}
	MyString& operator=(const MyString& str) {
		if (this == &str) {
			return *this;
		}
		if (buf != NULL) {
			delete[] buf;
		}
		buf = new char[str.len() + 1];
		strcpy(buf, str.c_str());
		return *this;
	}
	~MyString() {
		delete[] buf;
	}
	int len() const {
		return strlen(buf);
	}
	char* c_str() const { return buf; }
private:
	char* buf;
};


class List {
	struct Node {
		int val = 0;
		Node* next = nullptr;
	};
public:
	List():head(nullptr) {}
	~List() {
		Node* curNode = head;
		Node* next = nullptr;
		while (curNode) {
			next = curNode->next;
			curNode = next;
			if (next) {
				delete next;
			}
		}
		delete head;
	}
	void append(int val) {
		Node* node = new Node;
		node->val = val;
		if (head == nullptr) {
			head = node;
			return;
		}
		Node* curNode = head;
		while (curNode->next) {
			curNode = curNode->next;
		}
		curNode->next = node;
	}
	void print() {
		Node* curNode = head;
		while (curNode) {
			cout << curNode->val << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}

	void reversal() {
		Node* prev = nullptr;
		Node* current = head;
		Node* next = nullptr;

		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		// 最后将头节点指向原来链表的尾节点
		head = prev;
	}
private:
	Node* head;
};

class TreeBase {
public:
	TreeBase() {
		cout << "TreeBase::TreeBase()" << endl;
	}
	virtual ~TreeBase() {
		cout << "TreeBase::~TreeBase()" << endl;
	}
};
class AppleTree : public TreeBase {
public:
	AppleTree() {
		cout << "AppleTree::AppleTree()" << endl;
	}
	~AppleTree() {
		cout << "AppleTree::~AppleTree()" << endl;
	}

};

void reverseString(char *str) {
	int length = strlen(str);
	int start = 0, end = length - 1;
	char temp;

	while (start < end) {
		// 交换字符
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}
int myAtoi(const char* str) {
	int num = 0;
	int i = 0;
	int flag = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
		i++;
	}
	if (str[i] == '+') {
		i++;
	} else if (str[i] == '-') {
		i++;
		flag = -1;
	}
	while (str[i] >= '0' || str[i] <= '9') {
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return flag * num;
}
void myItoa(int num, char* str) {
	int i = 0;
	while (num != 0) {
		int rem = num % 10;
		str[i] = rem + '0';
		num = num / 10;
		++i;
	}
	str[i] = '\0';
	reverseString(str);
}
void myStrcpy(char* target ,const char* source) {
	int i = 0;
	while (source[i] != 0) {
		target[i] = source[i];
		i++;
	}
	target[i] = 0;
}
int myStrlen(char* str) {
	int i = 0;
	while (str[i] != 0) {
		i++;
	}
	return i;
}
//
const char* sum2(vector<int> arry, int target){
	string str;
	for (int i : arry) {
		for (int j = i + 1; j < arry.size();j++) {
			if (i == j) continue;
			if (target == arry[i] + arry[j]) {
				char buf[10];
				itoa(i, buf,10);
				string tmpi = buf;
				itoa(j, buf, 10);
				string tmpj = buf;
				str += "[" + tmpi + "," + tmpj + "]";
				cout << "--------" << str.c_str() << endl;
			}
		}
	}
	return str.c_str();
}

class Solution
{
public:
	//回文
	bool isrebackStr(char* str) {
		int len = strlen(str);
		int start = 0, end = len - 1;
		while (start < end) {
			if (str[start] != str[end]) {
				return false;
			}
			start++;
			end--;
		}
		return true;
	}
	//多个字符串中找最长前缀
	string beginLongStr(const vector<string>& strs) {
		int minLen = 0;
		string tmp;
		for (int i = 0; i < strs.size(); i++) {
			if (i == 0) {
				tmp = strs[0];
			}
			string tmp2;
			for (int j = 0; j < tmp.length(); j++) {
				if (tmp[j] == strs[i][j]) {
					tmp2 += tmp[j];
				}
			}
			tmp = tmp2;
		}
		return tmp;
	}
	//匹配括号
	bool matchBracket(const string& str) {
		stack<char> s;
		vector<char> leftBracket = { '{','(','[' };
		vector<char> rightBracket = { '}',')',']' };
		for (int i = 0; i < str.length(); i++) {
			for (auto ch : leftBracket) {
				if (ch == str[i]) {
					s.push(rightBracket[i]);
					break;
				}
			}
			for (int j = 0; j < rightBracket.size(); j++) {
				if (rightBracket[j] == str[i]) {
					s.pop();
					break;
				}
			}
		}
		return s.empty();
	}
	//括号组合
	string groupBracket(int n, vector<string>& strs) {
		if (n <= 0) {
			return "" ;
		}
		groupBracketTree("", n, n, strs);
		string result;
		for (string str : strs) {
			result += "[" + str +"]";
		}
		return result;
	}
	void groupBracketTree(string str, int left, int right, vector<string>& strs) {
		if (right == 0) {
			strs.push_back(str);
			return;
		}
		if (left == right) {
			groupBracketTree(str + '(', left - 1, right, strs);
		} else if (left < right) {
			if (left > 0) {
				groupBracketTree(str + '(', left - 1, right, strs);
			}
			groupBracketTree(str + ')', left, right - 1, strs);
		}
	}
	void insertStr(char* str, int pos, char* target) {
		int sourceLen = strlen(str);
		int targetLen = strlen(target);
		char* newStr = new char[sourceLen + targetLen + 1];

		int flag = false;
		int k = 0;
		for (int i = 0; i < sourceLen; i++){
			newStr[k] = str[i];
			k++;
			if (i == pos - 1) {
				flag = true;
				for (int j = 0; j < targetLen; j++) {
					newStr[k] = target[j];
					k++;
				}
			}
			
		}
		cout << "k:" << k << endl;
		if (flag == false) {
			for (int j = 0; j < targetLen; j++) {
				newStr[k] = target[j];
				k++;
			}
		}
		newStr[k] = 0;
		cout << "k:" << k << endl;
		//delete[] str;
		str = newStr;
		cout << "字符串插入:" << newStr << endl;
	}
	//爬楼梯
	void upFunc(int n, int* total) {
		if (n <= 0) {
			*total += 1;
			return;
		}
		if (n >= 2) {
			upFunc(n - 1, total);
			upFunc(n - 2, total);
		} else if(n >= 1) {
			upFunc(n - 1, total);
		}
	}
	//平方根
	int squareRoot(int x) {
		if (x <= 1) return x;
		int left = 0;
		int right = x;
		int mid;
		while (right >= left) {
			mid = (right + left) / 2;
			if (mid * mid >= x) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		return
	}
};

int main() {
	List list;
	list.append(0);
	list.append(1);
	list.append(2);
	list.reversal();
	string str;
	vector<int> arry = { 6,15,1,7,2,4,8,17 };
	//sort(arry, [&](int a, int b)->bool {return a > b; });
	char buf[] = "1234321";
	cout << "回文:" << Solution().isrebackStr(buf) << endl;
	vector<string> strs = { "flower","flow","flight" };
	cout << "多个字符串中找最长前缀:" << Solution().beginLongStr(strs).c_str() << endl;
	string matchBracket = "{[{(332}]}";
	cout << "匹配括号:" << Solution().matchBracket(matchBracket) << endl;
	vector<string> groupBrackets;
	cout << "括号组合:" << Solution().groupBracket(3, groupBrackets).c_str() << endl;
	char buf1[] = "1111";
	char buf2[] = "2222";
	Solution().insertStr(buf1, 1, buf2);
	cout << "字符串插入:" << buf1 << endl;
	int total = 0;
	Solution().upFunc(1, &total);
	cout << "爬楼梯1:" << total << endl;
	total = 0;
	Solution().upFunc(2, &total);
	cout << "爬楼梯2:" << total << endl;
	total = 0;
	Solution().upFunc(3, &total);
	cout << "爬楼梯3:" << total << endl;
	total = 0;
	Solution().upFunc(4, &total);
	cout << "爬楼梯4:" << total << endl;
	total = 0;
	Solution().upFunc(5, &total);
	cout << "爬楼梯5:" << total << endl;
	total = 0;
	Solution().upFunc(9, &total);
	cout << "爬楼梯9:" << total << endl;
	total = 0;
	Solution().upFunc(40, &total);
	cout << "爬楼梯18:" << total << endl;
	total = 0;
	//TreeBase* t = new AppleTree;
	//delete t;

	return 0;
}

