/*
 * Author	: ZhaoW
 * Time		: 2015-03-04  08:59:59
 * problem	: https://oj.leetcode.com/problems/lru-cache/
 *  Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
 * no compile, need c++11
  * */
 
#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*https://oj.leetcode.com/discuss/20619/c-11-code-74ms-hash-table-list*/ 
class LRUCache{
private:
	typedef pair<int, list<int>::iterator> Pvalue;
	typedef unordered_map<int, Pvalue>::iterator MapIter;
	
	int _capacity;
	list<int> lruList;
	unordered_map<int, Pvalue> cache;	
	
	void update_lru(MapIter iter)
	{
		int key = iter->first;
		lruList.erase(iter->second.second);
		lruList.push_front(key);
		iter->second.second = lruList.begin();
	}

public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        MapIter iter = cache.find(key);
		
		if (iter == cache.end())
		{
			return -1;
		}
		else
		{
			update_lru(iter);
			return iter->second.first;
		}
    }
    
    void set(int key, int value) {
        MapIter iter = cache.find(key);
		
		if (iter == cache.end())
		{ 
			if (cache.size() == _capacity)
			{
				cache.erase(lruList.back());
				lruList.pop_back();
			}
			lruList.push_front(key);
		}
		else
		{
			update_lru(iter);
		}
		cache[key] = {value, lruList.begin()};
    }

};
 
int main()
{
	int i;
	LRUCache test(3);
	test.set(1, 2);
	cout << test.get(1)<<endl;
	test.set(2, 4);
	test.set(3, 8);
	//test.print();
	test.set(1, 9);
	test.set(4, 16);
	//test.print();
	cin >> i;
	cout << i;
	return 0;
}
 