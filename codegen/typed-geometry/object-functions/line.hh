#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<line<D, ScalarT>>
{
    static constexpr auto edges(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto faces(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto vertices(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto volume(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto area(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto boundary(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto rasterize(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto triangulate(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto triangulation(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto centroid(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto aabb_of(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto any_point(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto project(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto signed_distance(line<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(line<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(line<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(line<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(line<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(line<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(line<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(line<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(line<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<line<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
};
