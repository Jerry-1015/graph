// @Author:			jerry
// @Date:			Wed Jun 22 14:39:35 CST 2022
// @Description:	quick find

#ifndef _QUICK_FIND_H_
#define _QUICK_FIND_H_

#include "IUnionFind.h"
#include <vector>

namespace graph {
class QuickFind : public IUnionFind {
public:
	QuickFind(int size) : id_(size) {
		for (int i = 0; i < size; i++) {
			id_[i] = i;
		}
	} 

	int size() const override {
		return id_.size();
	}

	bool is_conn(int p, int q) const override {
		return find(p) == find(q);
	}

	void union_set(int p, int q) override {
		int p_id = find(p);
		int q_id = find(q);
		if (p_id == q_id) return;

		for (int i = 0; i < id_.size(); i++) {
			if (id_[i] == p_id) 
				id_[i] = q_id;
		}
	}


private:
	int find(int p) const { 
		return id_[p];
	}

private:
	std::vector<int> id_;
};
}

#endif // _QUICK_FIND_H_
