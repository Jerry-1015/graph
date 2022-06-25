// @Author:			jerry
// @Date:			Wed Jun 22 15:13:08 CST 2022
// @Description:	quick union

#ifndef _QUICK_UNION_H_
#define _QUICK_UNION_H_

#include "IUnionFind.h"
#include <vector>

namespace graph {
class QuickUnion : public IUnionFind {
public:
	QuickUnion(int size) : parent_(size) {
		for (int i = 0; i < size; i++) {
			parent_[i] = i;
		}
	}

	int size() const override {
		return parent_.size();
	}

	bool is_conn(int p, int q) const override {
		return find(p) == find(q);
	}

	void union_set(int p, int q) override {
		int p_root = find(p);
		int q_root = find(q);
		if (p_root == q_root) return;

		parent_[p_root] = q_root;
	 }

private:
	int find(int p) const  {
		while (p != parent_[p]) {
			p = parent_[p];
		}
		return p;
	}


private:
	std::vector<int> parent_;
};
}


#endif // _QUICK_UNION_H_
