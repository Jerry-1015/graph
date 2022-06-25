// @Author:			jerry
// @Date:			Tue Jun 21 17:24:51 CST 2022
// @Description:	BFS

#ifndef _BFSGRAPH_H_
#define _BFSGRAPH_H_

#include "IGraph.h"
#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>

namespace graph {
class BFSGraph {
public:
	BFSGraph(IGraph* graph) : graph_(graph) 
							 , visited_(graph_->get_vertex_num(), false)
	{
		for(int v = 0; v < graph_->get_vertex_num(); ++v) {
			if (!visited_[v]) 
				BFS(v);
		}
    }
	BFSGraph(const BFSGraph&) = delete;
	BFSGraph(const BFSGraph&&) = delete;
	BFSGraph& operator=(const BFSGraph&) = delete;
	BFSGraph& operator=(const BFSGraph&&) = delete;

	std::vector<int> get_list() {
		return list_;
	}

private:
	void BFS(int s) {
		visited_[s] = true;
		que_.push(s);
		while (!que_.empty()) {
			int v = que_.front();
			list_.push_back(v);
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
	std::vector<bool> visited_;
	std::vector<int> list_;
	std::queue<int> que_;
};
}

#endif // _BFSGRAPH_H_
