/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:14:30 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/07 15:51:25 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_rt	*ft_clean(t_rt *r)
{
	t_light	*al;
	t_light	*temp;

	free((void**)(r->obj));
	r->obj = NULL;
	al = r->light;
	while (al)
	{
		temp = al->next;
		ft_strdel(&(temp->type));
		free(al);
		al = temp;
	}
	r->light = NULL;
	free(r);
	r = NULL;
	return (r);
}

void	ft_init(t_rt *r)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		if ((r->win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,\
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
			if ((r->ren = SDL_CreateRenderer(r->win, -1,
												SDL_RENDERER_ACCELERATED)))
				return ;
	ft_putendl(SDL_GetError());
	ft_clean(r);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_rt		*r;
	SDL_Event	event;

	if (argc != 2)
		ft_put_error("Usage: ./RTv1 [path of file]");
	if (!(r = (t_rt *)malloc(sizeof(t_rt))))
		ft_put_error("Allocation memory error");
	r->count = 0;
	r->amount_obj = 0;
	r->s = 0;
	r->light = NULL;
	ft_parser(argv[1], r);
	ft_init(r);
	ft_render(r);
	SDL_RenderPresent(r->ren);
	while (1)
		while (SDL_PollEvent(&event))
			if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type &&\
				SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
			{
				ft_clean(r);
				exit(0);
			}
}
