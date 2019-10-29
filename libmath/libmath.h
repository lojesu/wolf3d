/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:47:44 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/09 10:34:45 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_pt
{
	double		x;
	double		y;
	double		z;
}				t_pt;

double			deg_to_rad(double deg);
double			rad_to_deg(double rad);
double			equation_2_deg(double a, double b, double c);
t_vec			mul_vec(t_vec a, double m);
t_vec			vec(t_pt a, t_pt b);
double			size_vec(t_vec v);
t_vec			unit_vec(t_vec v);
double			dot_vec(t_vec a, t_vec b);
t_vec			cross_product(t_vec a, t_vec b);
t_pt			add_pt(t_pt a, t_pt b);
t_pt			sub_pt(t_pt a, t_pt b);
t_pt			move_pt(t_pt p, t_vec v);
t_vec			add_vec(t_vec a, t_vec b);
t_vec			sub_vec(t_vec a, t_vec b);
t_vec			div_vec(t_vec v, double d);

#endif
