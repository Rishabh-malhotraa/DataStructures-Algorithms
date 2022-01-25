package main

const UNVISTED, ENQUEUE, VISITED int = 0, 1, 2

func buildGraph(edgeList [][]int, n int) [][]int {
	graph := make([][]int, n)
	for _, edge := range edgeList {
		// edge[1] -> edge[0]
		u, v := edge[1], edge[0]
		graph[u] = append(graph[u], v)
	}
	return graph
}

/*
 1 -> 2 -> 3
      |    |
			v		 V
			5	-> 4

	4 -> 5 -> 3 -> 2 -> 1
*/

func acyclic(course int, graph [][]int, visit []int, schedule *[]int) bool {
	visit[course] = ENQUEUE

	for _, nextCourse := range graph[course] {
		if visit[nextCourse] == ENQUEUE {
			return false
		}
		if visit[nextCourse] == UNVISTED && !acyclic(nextCourse, graph, visit, schedule) {
			return false
		}
	}

	*schedule = append(*schedule, course)

	visit[course] = VISITED

	return true
}

// 1 2 3 4 5
func reverse(A []int) []int {
	n := len(A)
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		A[i], A[j] = A[j], A[i]
	}
	return A
}

func findOrder(numCourses int, prerequisites [][]int) []int {

	graph := buildGraph(prerequisites, numCourses)
	visit := make([]int, numCourses)

	var schedule []int

	for i := range visit {
		visit[i] = UNVISTED
	}

	for course := range graph {
		if visit[course] == UNVISTED {
			if acyclic(course, graph, visit, &schedule) == false {
				return []int{}
			}
		}
	}
	schedule = reverse(schedule)

	return schedule
}
