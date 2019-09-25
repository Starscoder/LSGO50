/**

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
**/


class LRUCache {
private:
    int cap;
    list< pair<int,int> > cache;
    unordered_map<int, list<pair<int,int>>::iterator>  map;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it == map.end()) return -1;
        pair<int,int> kv = *map[key];
        cache.erase(map[key]);      //将key键值对从cache中删除
        cache.push_front(kv);        //将key键值对加到cache队首
        map[key] = cache.begin();      //更新map[key]的位置
        return kv.second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it == map.end()){
            if(cache.size() == cap){
                auto last = cache.back();
                int lastKey = last.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            cache.push_front(make_pair(key,value));
            map[key] = cache.begin();
        }
        else{
            cache.erase(map[key]);
            cache.push_front(make_pair(key,value));
            map[key] = cache.begin();
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
