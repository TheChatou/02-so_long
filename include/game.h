/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:15:55 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/02 16:59:45 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

//// KEYS ////
# define ESC 			65307	// key escape
# define KEY_Q			113

# define WALL			'.'
# define EMPTY			' '
# define BAD			'B'
# define EXIT			'E'
# define TOKEN			'T'
# define PLAYER			'P'

# define KEY_W			119		// key "arrow up"
# define KEY_A			97		// key "arrow left"
# define KEY_S			115		// key "arrow down"
# define KEY_D			100		// key "arrow right"

# define UP 			65362	// key "arrow up"
# define LEFT 			65361	// key "arrow left"
# define DOWN 			65364	// key "arrow down"
# define RIGHT 			65363	// key "arrow right"

//// XPM PATHS ////
# define PA_0			"./assets/0n2.xpm"		// nums
# define PA_1			"./assets/1n2.xpm"		//
# define PA_2			"./assets/2n2.xpm"		//
# define PA_3			"./assets/3n2.xpm"		//
# define PA_4			"./assets/4n2.xpm"		//
# define PA_5			"./assets/5n2.xpm"		//
# define PA_6			"./assets/6n2.xpm"		//
# define PA_7			"./assets/7n2.xpm"		//
# define PA_8			"./assets/8n2.xpm"		//
# define PA_9			"./assets/9n2.xpm"		//
# define PA_10			"./assets/wall.xpm"		// WALL
# define PA_11			"./assets/empty.xpm"	// EMPTY
# define PA_12			"./assets/exit_cl.xpm"	// EXIT Closed
# define PA_13			"./assets/exit_op.xpm"	// EXIT Openned

# define PA_PLAYER			"./assets/felix.xpm"	// Player Big_frame
# define PA_TOKENS			"./assets/token.xpm"	// Tokens Big_frame

//// SIZE & DELAY ///
# define SIZE 			32		// Sprite size
# define FPS 			12		// Frames Per Second

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		h;
	int		w;
}			t_win;

// tk_pos		// Good Tokens Position
// tk_cc		// Good Tokens Counter
// t_tk			// Good Tokens Total
// bad_pos		// Bad Tokens Position
// t_bad		// Bad Tokens Counter
// pl_pos		// Player Tokens Position
// pl_cc		// Player Tokens Counter
typedef struct s_map
{
	char		**map;
	t_point		*tk_pos;
	int			tk_cc;
	int			t_tk;
	t_point		*bad_pos;
	int			t_bad;		
	int			valid;		
	t_point		pl_pos;
	int			pl_cc;
	t_point		exit;
	int			exit_cc;
	t_point		size;
}			t_map;

typedef struct s_slice
{
	t_point	pos;
	int		w;
	int		h;
}			t_slice;

typedef struct s_img
{
	t_win	win;
	void	*xpm_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

// cur_frame		// Current Frame
// frame_cc			// Frame Counter
// bigfra			// Big Frame t_img struct
typedef struct s_anim
{
	t_list			*frames;
	char			*file_path;
	int				w;
	int				h;
	int				cur_frame;
	int				last_updated;
	int				frame_cc;
	t_img			bigfra;
	t_slice			slice;
}				t_anim;

// sta_pl		// Static Player
// walk_pl		// Walking Player
// good_tk		// Good Tokens
// bad_tk		// Bad Tokens
typedef struct s_game
{
	t_win		win;
	int			w;
	int			h;
	void		*xpm_ptr[14];
	char		*xpm_paths[14];
	void		*xpm_switch;
	int			moves;
	int			dir;
	t_map		map;
	t_anim		sta_pl;
	t_anim		walk_pl;
	t_anim		good_tk;
	t_anim		bad_tk;
}				t_game;

#endif