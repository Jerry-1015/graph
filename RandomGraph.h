// @Author:			jerry
// @Date:			Wed Jun 22 11:55:08 CST 2022
// @Description:	random search

#ifndef _RANDOMGRAPH_H_
#define _RANDOMGRAPH_H_

#include "IGraph.h"
#include <cstddef>
#include "Utility.h"
#include <iostream>
#include <vector>
#include <queue>


namespace graph {
class RandomGraph {
public:
	RandomGraph(IGraph* graph) : graph_(graph) 
							 , visited_(graph_->get_vertex_num(), false)
	{
		for(int v = 0; v < graph_->get_vertex_num(); ++v) {
			if (!visited_[v]) 
				RFS(v);
		}
    }
	RandomGraph(const RandomGraph&) = delete;
	RandomGraph(const RandomGraph&&) = delete;
	RandomGraph& operator=(const RandomGraph&) = delete;
	RandomGraph& operator=(const RandomGraph&&) = delete;

	std::vector<int> get_list() {
		return list_;
	}

private:
	void RFS(int s) {
		visited_[s] = true;
		que_.push_back(s);
		while (!que_.empty()) {
			int v = que_.pop_random();
			list_.push_back(v);
			for (auto w : graph_->get_adj(v)) {
				if (!visited_[w]) {
					visited_[w] = true;
					que_.push_back(w);
				}
					
			}
		}
	}


private:
	IGraph* graph_;
	std::vector<bool> visited_;
	std::vector<int> list_;
	graph::random_deque<int> que_;
};
}

#endif // _RANDOMGRAPH_H_
