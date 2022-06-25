// @Author:			jerry
// @Date:			Tue Jun 21 14:16:15 CST 2022
// @Description:	detecte cycle

#ifndef _DFS_CYCLE_DETECTION_PATH_H_
#define _DFS_CYCLE_DETECTION_PATH_H_

#include "IGraph.h"
#include <algorithm>
#include <cstddef>
#include <vector>


namespace graph {
class DFSCycleDetection {
public:
	DFSCycleDetection(IGraph* graph) : graph_(graph), has_cycle_(false) 
						     , pre_(graph_->get_vertex_num(), -1)
							 , visited_(graph_->get_vertex_num(), false)
	{
		for (int v = 0; v < graph_->get_vertex_num();++v) {
			if (!visited_[v])
				DFS(v);
		}
	}
	DFSCycleDetection(const DFSCycleDetection&) = delete;
	DFSCycleDetection(const DFSCycleDetection &&) = delete;
	DFSCycleDetection& operator=(const DFSCycleDetection&) = delete;
	DFSCycleDetection& operator=(const DFSCycleDetection &&) = delete;

	bool has_cycle() {
		return has_cycle_;
	}

private:
	void DFS(int v) {
		visited_[v] = true;
		for (auto w : graph_->get_adj(v)) {
			if (!visited_[w]) {
				pre_[w] = v;
				DFS(w);
			} else if (w != pre_[v]) {
				has_cycle_ = true;
			}
		}
	}

private:
	IGraph* graph_;
	bool has_cycle_;
	std::vector<int> pre_;
	std::vector<bool> visited_;
		
};
}


#endif // _DFS_CYCLE_DETECTION_PATH_H_
