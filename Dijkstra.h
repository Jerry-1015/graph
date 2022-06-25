// @Author:			jerry
// @Date:			Fri Jun 24 21:07:29 CST 2022
// @Description:	Dijkstra

#include "IGraph.h"
#include "AdjDictionary.h"
#include <vector>
#include <limits>

namespace graph {
class Dijkstra {
public:
	Dijkstra(IGraph *graph, int s) : graph_(graph), s_(s)
	, dis_(graph_->get_vertex_num(), std::numeric_limits<double>::max()) , visited_(graph_->get_vertex_num(), false)
	{
		dis_[s_] = 0;

		while(true) {
			int cur = -1;
			double cur_dis = std::numeric_limits<double>::max();

			for (int v = 0; v < graph_->get_vertex_num(); ++v) {
				if (!visited_[v] && dis_[v] < cur_dis) {
					cur_dis = dis_[v];
					cur = v;
				}
			}

			if (cur == -1) break;

			visited_[cur] = true;

			for (auto w : graph_->get_adj(cur)) {
				if (!visited_[w]) {
					if (dis_[cur] + ((AdjDictionary*)graph_)
						->get_weight(cur, w) < dis_[w]) {

						dis_[w] = dis_[cur] + ((AdjDictionary*)graph_)
						->get_weight(cur, w);
					}
				}
			}
		}
	}

	bool is_conn_to(int t) {
		return visited_[t];
	}

	double dist_to(int v) {
		return dis_[v];
	}
private:
	IGraph *graph_;
	int s_;
	std::vector<double> dis_;
	std::vector<bool> visited_;

};
}
