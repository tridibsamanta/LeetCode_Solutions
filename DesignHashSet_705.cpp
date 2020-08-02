/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 705. Design HashSet
~ Link      : https://leetcode.com/problems/design-hashset/
*/

class MyHashSet {

private:

    const int size = 200;
    vector<vector<int> *> set;

public:

	MyHashSet() {
		set.resize(size);
	}

	void add(int key) {

		int index = key % size;

		if (!contains(key))
		{
			auto v = set[index];

			if (v == nullptr)
				v = new vector<int>;

			v->push_back(key);
            set[index] = v;
		}
	}

	void remove(int key) {

		int index = key % size;

		auto v = set[index];

		if (v == nullptr)
            return;

		for (auto = v->begin(); iter != v->end(); iter++) {
			if (*iter == key) {
				v->erase(iter);
				return;
			}
		}
	}

	bool contains(int key) {

		int index = key % size;

		auto v = set[index];

		if (v == nullptr)
            return false;

		for (auto e : *v) {
			if (e == key)
				return true;
		}

		return false;
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
