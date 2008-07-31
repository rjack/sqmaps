/*
 * Copyright (c) 2008 Giacomo Ritucci
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GIACOMO RITUCCI ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 * NO EVENT SHALL GIACOMO RITUCCI BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "h/graph.h"

#include <stdlib.h>


/****************************************************************************
			       Public functions
****************************************************************************/

graph_t *
graph_create (size_t node_quantity)
{
	/* TODO */
	return NULL;
}


int
graph_add_vertex (vertex_t *new_vertex)
{
	/* TODO */
	return 0;
}


int
graph_arch_create
(vertex_t *from_vertex, vertex_t *to_vertex, arch_weight_t weight)
{
	/* TODO */
	return 0;
}


vertex_t *
vertex_create (vertex_id_t *id, vertex_value_t value)
{
	/* TODO */
	return NULL;
}


graph_iterator_t *
graph_get_iterator (graph_t *graph)
{
	/* TODO */
	return NULL;
}


vertex_t *
graph_iterator_get_next (graph_iterator_t *iterator)
{
	/* TODO */
	return NULL;
}


vertex_t *
graph_get_vertex (vertex_id_t *id)
{
	/* TODO */
	return NULL;
}


bfs_context_t *
bfs_context_create (graph_t *graph, vertex_id_t *source_id)
{
	/* TODO */
	return NULL;
}


void
bfs_context_destroy (bfs_context_t *bfs_context)
{
	/* TODO */
}


path_t *
bfs_run (bfs_context_t *bfs_context)
{
	/* TODO */
	return NULL;
}
