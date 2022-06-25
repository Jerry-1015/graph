// @Author:			jerry
// @Date:			Tue Jun 21 16:41:38 CST 2022
// @Description:	count components by BFS

#ifndef _BFSCC_H_
#define _BFSCC_H_

#include "IGraph.h"
#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>

namespace graph {
class BFSCC {
public:
	BFSCC(IGraph* graph) : graph_(graph), ccount_(0)
							 , visited_(graph_->get_vertex_num(), false)
	{
		for(int v = 0; v < graph_->get_vertex_num(); ++v) {
			if (!visited_[v]) {
				BFS(v);
				++ccount_;
			}
		}
    }
	BFSCC(const BFSCC&) = delete;
	BFSCC(const BFSCC&&) = delete;
	BFSCC& operator=(const BFSCC&) = delete;
	BFSCC& operator=(const BFSCC&&) = delete;

	int get_components() {
		return ccount_;
	}

private:
	void BFS(int s) {
		visited_[s] = true;
		que_.push(s);
		while (!que_.empty()) {
			int v = que_.front();
			que_.pop();
			for (auto w : graph_->get_adj(v)) {
				if (!visited_[w]) {
					visited_[w] = true;
					que_.push(w);
				}
					
			}
		}
	}


private:
	IGraph* graph_;
	int ccount_;
	std::vector<bool> visited_;
	std::queue<int> que_;
};
}

#endif // _BFSCC_H_
