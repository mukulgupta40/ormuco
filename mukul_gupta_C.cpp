#include <bits/stdc++.h>
using namespace std;


struct entry_in_cache {
    string data;
    chrono::system_clock::time_point time_to_expire;
};

//LRU cache class
class LRU_cache_geo {
private:
    int max_size;
    unordered_map<string, list<string>::iterator> interator_key_to_list;
    list<string> lru_cache_list;
    unordered_map<string, entry_in_cache> cache;

public:
    LRU_cache_geo(int size) : max_size(size) {}

    // Add a key-value pair to the cache
    void put(string key, string value, int time_in_seconds) {

        if (cache.size() >= max_size) {  //removing lru entry when full
            string lru_key = lru_cache_list.back();
            cache.erase(lru_key);
            lru_cache_list.pop_back();
        }

        cache[key] = {value, chrono::system_clock::now() + chrono::seconds(time_in_seconds)}; //add entry
        lru_cache_list.push_front(key);
        interator_key_to_list[key] = lru_cache_list.begin();
    }

	//get value corresponding to the key
    string get(string key) {
        if (cache.find(key) == cache.end() || cache[key].time_to_expire <= chrono::system_clock::now()) {
            return "Key you have entered has expired or not entered";
        }

        // Move the key entered to the front
        lru_cache_list.erase(interator_key_to_list[key]);
        lru_cache_list.push_front(key);
        interator_key_to_list[key] = lru_cache_list.begin();

        return cache[key].data;
    }
};

int main() {
    int cache_size;
    cout<<"enter cache size";
    cin>>cache_size;
    LRU_cache_geo cache(cache_size);

    //add key-value pair with time to live
    for(int i=0;i<cache_size;i++){
    	string k,v;
    	int t;
    	cout<<"enter key value";
    	cin>>k;
    	cout<<"enter value";
    	cin>>v;
    	cout<<"enter time to live";
    	cin>>t;
    	cache.put(k,v,t);
	}

    // Retrieve values from the cache
    string k1;
    while(1){
    	cout<<"enter key value, to exit type q";
    	cin>>k1;
    	if(k1=="q"){
    		break;
		}
    	cout << "Value for key: " << cache.get(k1)<<"\n";
	}

    return 0;
}

