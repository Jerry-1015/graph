// @Author:			jerry
// @Date:			Tue Jun 21 14:41:06 CST 2022
// @Description:	Bipartition Detection

#ifndef _DFS_BIPARTITION_DETECION_H_
#define _DFS_BIPARTITION_DETECION_H_

#include "IGraph.h"
#include <cstddef>
#include <vector>


namespace graph {
class DFSBipartitionDetection {
public:
	DFSBipartitionDetection(IGraph* graph) : graph_(graph), is_bipartite_(true)
							 , visited_(graph_->get_vertex_num(), false)
							 , colors_(graph_->get_vertex_num()) 
	{
		for (int v = 0; v < graph_->get_vertex_num(); ++v)	{
			if (!visited_[v])
				DFS(v);
		}
	}
	DFSBipartitionDetection(const DFSBipartitionDetection&) = delete;
	DFSBipartitionDetection(const DFSBipartitionDetection &&) = delete;
	DFSBipartitionDetection& operator=(const DFSBipartitionDetection&) = delete;
	DFSBipartitionDetection& operator=(const DFSBipartitionDetection &&) = delete;

	bool is_bipartite() const {
		return is_bipartite_;
	}

private:
	void DFS(int v) {
		visited_[v] = true;
		for (auto w : graph_->get_adj(v)) {
			if (!visited_[w]) {
				colors_[w] = !colors_[v];
				DFS(w);
			} else if (colors_[w] == colors_[v]) {
				is_bipartite_ = false;
				return;
			}
		}
	}

private:
	IGraph* graph_;
	bool is_bipartite_;
	std::vector<bool> visited_;
	std::vector<bool> colors_;
};
}


#endif // _DFS_BIPARTITION_DETECION_H_
