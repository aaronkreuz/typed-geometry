#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<sphere<D, ScalarT>>
{
    static constexpr auto edges(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto faces(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto vertices(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto volume(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto area(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto boundary(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto rasterize(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto triangulate(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto triangulation(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto centroid(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto aabb_of(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto any_point(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto project(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto signed_distance(sphere<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(sphere<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(sphere<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(sphere<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(sphere<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(sphere<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(sphere<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(sphere<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(sphere<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<sphere<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
};
