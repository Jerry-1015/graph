// @Author:			jerry
// @Date:			Wed Jun 22 09:52:01 CST 2022
// @Description:	cycle detection by BFS

#ifndef _BFS_CYCLE_DETECTION_H_
#define _BFS_CYCLE_DETECTION_H_

#include "IGraph.h"
#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>

namespace graph {
class BFSCycleDetection {
public:
	BFSCycleDetection(IGraph* graph) : graph_(graph), has_cycle_(false) 
							 , visited_(graph_->get_vertex_num(), false)
							 , pre_(graph_->get_vertex_num(), -1)
	{
		for(int v = 0; v < graph_->get_vertex_num(); ++v) {
			if (!visited_[v]) 
				BFS(v);
		}
    }
	BFSCycleDetection(const BFSCycleDetection&) = delete;
	BFSCycleDetection(const BFSCycleDetection&&) = delete;
	BFSCycleDetection& operator=(const BFSCycleDetection&) = delete;
	BFSCycleDetection& operator=(const BFSCycleDetection&&) = delete;

	bool has_cycle() const {
		return has_cycle_;
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
					pre_[w] = v;
					que_.push(w);
				} else if (w != pre_[v]) {
					has_cycle_ = true;
					return;
				}
					
			}
		}
	}


private:
	IGraph* graph_;
	bool has_cycle_;
	std::vector<bool> visited_;
	std::queue<int> que_;
	std::vector<int> pre_;
};
}

#endif // _BFS_CYCLE_DETECTION_H_
