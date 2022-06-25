// @Author:			jerry
// @Date:			Tue Jun 21 22:46:43 CST 2022
// @Description:	detecte bipartition

#ifndef _BFS_BIPARTITION_DETECTION_H_
#define _BFS_BIPARTITION_DETECTION_H_

#include "IGraph.h"
#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>

namespace graph {
class BFSBipartitionDetection {
public:
	BFSBipartitionDetection(IGraph* graph) : graph_(graph), is_bipartition_(true)
							 , visited_(graph_->get_vertex_num(), false)
							 , colors_(graph_->get_vertex_num())
	{
		for(int v = 0; v < graph_->get_vertex_num(); ++v) {
			if (!visited_[v]) 
				BFS(v);
		}
    }
	BFSBipartitionDetection(const BFSBipartitionDetection&) = delete;
	BFSBipartitionDetection(const BFSBipartitionDetection&&) = delete;
	BFSBipartitionDetection& operator=(const BFSBipartitionDetection&) = delete;
	BFSBipartitionDetection& operator=(const BFSBipartitionDetection&&) = delete;
	
	bool is_bipartition() const {
		return is_bipartition_;
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
					colors_[w] = !colors_[v];
					que_.push(w);
				} else if (colors_[w] == colors_[v]) {
					is_bipartition_ = false;
					return;
				}
					
			}
		}
	}


private:
	IGraph* graph_;
	bool is_bipartition_;
	std::vector<bool> visited_;
	std::queue<int> que_;
	std::vector<bool> colors_;
};
}

#endif // _BFS_BIPARTITION_DETECTION_H_
