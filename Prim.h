// @Author:			jerry
// @Date:			Fri Jun 24 16:23:41 CST 2022
// @Description:	prim algorithm

#ifndef _PRIM_H_
#define _PRIM_H_

#include "IGraph.h"
#include "IUnionFind.h"
#include "AdjDictionary.h"
#include "Utility.h"
#include "BFSCC.h"
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

namespace graph {
class Prim {
public:
	Prim(IGraph *graph) : graph_(graph)
						, colors_(graph_->get_vertex_num(), false)    	 
	{
		BFSCC cc(graph);
		if (cc.get_components() > 1) return;

		colors_[0] = true;
		for (int i = 1; i < graph_->get_vertex_num(); i++) {
			Edge min_edge(-1, -1, std::numeric_limits<double>::max());

			for (int a = 0; a < graph_->get_vertex_num(); ++a) {
				if (colors_[a]) {
					for (auto b : graph_->get_adj(a)) {
						if (!colors_[b] 
							&& ((AdjDictionary*)graph_)
							    ->get_weight(a, b)
								< min_edge.get_weight()) 
							min_edge = Edge(a, b 
									   , ((AdjDictionary*)graph_)
								       ->get_weight(a, b));

					}
				}
			}

			list_.push_back(min_edge);

			colors_[min_edge.get_v_a()] = true;
			colors_[min_edge.get_v_b()] = true;
		}

	}

	std::vector<Edge> get_list () const {
		return list_;
	}

private:
	IGraph *graph_;
	std::vector<Edge> list_;
	std::vector<bool> colors_;
};
}

#endif // _PRIM_H_
