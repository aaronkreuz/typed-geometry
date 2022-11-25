#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<aabb<D, ScalarT>>
{
    static constexpr auto edges(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto faces(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto vertices(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto volume(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto area(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto boundary(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto rasterize(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto triangulate(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto triangulation(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto centroid(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto aabb_of(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto any_point(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto project(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto signed_distance(aabb<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(aabb<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(aabb<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(aabb<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(aabb<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(aabb<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(aabb<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(aabb<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(aabb<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<aabb<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
};
