// @Author:			jerry
// @Date:			Wed Jun 22 17:29:01 CST 2022
// @Description:	Kruskal

#ifndef _KRUSKAL_H_
#define _KRUSKAL_H_

#include "Utility.h"
#include "IGraph.h"
#include "AdjDictionary.h"
#include "DFSCC.h"
#include "IUnionFind.h"
#include "QuickUnion.h"
#include <iostream>
#include <vector>

namespace graph {
class Kruskal {
public:
	Kruskal(IGraph* graph) : graph_(graph) { 
		DFSCC cc(graph_);
		if (cc.get_components() > 1) return;

		std::vector<Edge> edges;
		for (int a = 0; a < graph_->get_vertex_num(); ++a) {
			for (auto b : graph_->get_adj(a)) {
				if (a < b) {
					Edge e(a, b, 
						((AdjDictionary*)graph_)->get_weight(a,b));
					edges.push_back(e);
				}
			}
		}
		std::sort(edges.begin(), edges.end());
		
		IUnionFind *uf = new QuickUnion(graph_->get_vertex_num());
		for (const auto& e : edges) {
			int a = e.get_v_a();
			int b = e.get_v_b();
			if (!uf->is_conn(a, b)) {
				list_.push_back(e);
				uf->union_set(a, b);
			} 
		}
	}

	std::vector<Edge> get_list() const {
		return list_;
	}
		
private:

	// bool sift_down(int idx, int n) {
	// 	if (idx >= n) return false;
	// 	int son = 2 * idx + 1;
	// 	int flag = false;
	// 	while (son < n) {
	// 		if (son + 1 < n && list_[son + 1] < list_[son])
	// 			++son;
	// 		if (list_[son] < list_[idx])
	// 			list_[idx].swap(list_[son]);
	// 		idx = son;
	// 		son = 2 * idx + 1;
	// 		flag = true;
	// 	}
	// 	return flag;
	// }

	// void build_heap() {
	// 	int i = (list_.size() - 2) / 2;
	// 	for (; i >= 0; --i) 
	// 		sift_down(i, list_.size());
	// }

	// void heap_sort() {
	// 	build_heap();
	// 	int n = list_.size() - 1;
	// 	while (n >= 0) {
	// 		list_[0].swap(list_[n]);
	// 		sift_down(0, n);
	// 		--n;
	// 	}
	// }


private:
	IGraph *graph_;
	std::vector<Edge> list_;
};
}



#endif // _KRUSKAL_H_
