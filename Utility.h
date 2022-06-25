#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

namespace graph {
	template<typename type>
	void split(std::string str, char split, std::vector<type>& res) {
		res.clear();
		std::stringstream line(str);
		std::string temp;
		while(getline(line, temp, split)) {
			std::stringstream convertion;
			convertion << temp;
			type element;
			convertion >> element;
			res.push_back(element);
		}
	}

template <typename type>
class random_deque {
public:
	random_deque<type> () = default;
	random_deque<type> (int size) : que(size) { }
	void push_back(type t) {
		que.push_back(t);
	}

	type pop_random() {
		srand(time(0));
		double range = (rand() % 100) / 100.0;
		int random_index = range * que.size();
		type res = que[random_index];
		que[random_index] = que.back();
		que.pop_back();
		return res;
	}

	bool empty() const {
		return que.empty();
	}

	size_t size() const {
		return que.size();
	}

private:
	std::deque<type> que;
};

class Edge {
public:
	Edge(int a, int b, double w) : v_a_(a), v_b_(b), w_(w) { }

	bool operator<(const Edge& e) {
		return this->w_ < e.w_;
	}
	bool operator>(const Edge& e) {
		return this->w_ > e.w_;
	}
	Edge& operator=(const Edge& e) {
		this->v_a_ = e.v_a_;
		this->v_b_ = e.v_b_;
		this->w_ = e.w_;
		return *this;
	}

	void swap(Edge &e) {
		std::swap(this->v_a_, e.v_b_);
		std::swap(this->v_b_, e.v_b_);
		std::swap(this->w_, e.w_);
	}

	int get_v_a() const {
		return v_a_;
	}
	int get_v_b() const {
		return v_b_;
	}
	double get_weight() const {
		return w_;
	}
private:
	int v_a_;
	int v_b_;
	double w_;
};
}

#endif
