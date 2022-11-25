#pragma once

#include <typed-geometry/object_functions.hh>

template <int D, class ScalarT>
struct object_functions<ray<D, ScalarT>>
{
    static constexpr auto edges(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto faces(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto vertices(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto volume(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto area(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto boundary(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto rasterize(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto triangulate(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto triangulation(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto centroid(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto aabb_of(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto any_point(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto project(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto signed_distance(ray<D, ScalarT> const& obj)
    {
        static_assert(cc::always_false<ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersects(ray<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection(ray<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto closest_points(ray<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance(ray<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto distance_sqr(ray<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameter(ray<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto intersection_parameters(ray<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, pos<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,pos<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, ray<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ray<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, line<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,line<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, seg<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,seg<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, aabb<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, sphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, triangle<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,triangle<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, plane<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,plane<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, aabb_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,aabb_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, box<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, box_boundarycapsule<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,box_boundarycapsule<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, capsule_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,capsule_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, cone_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cone_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, cylinder_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,cylinder_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, ellipse<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, ellipse_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,ellipse_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, halfspace<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,halfspace<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, hemisphere<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, hemisphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, hemisphere_boundary_no_caps<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,hemisphere_boundary_no_caps<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, inf_cone<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, inf_cone_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cone_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, inf_cylinder<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, inf_cylinder_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_cylinder_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, inf_frustum<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,inf_frustum<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, quad<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,quad<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, sphere_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,sphere_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, disk<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk<D, ScalarT>>, "TODO: not yet implemented");
    }
    
    static constexpr auto contains(ray<D, ScalarT> const& a, disk_boundary<D, ScalarT> const& b)
    {
        static_assert(cc::always_false<ray<D, ScalarT>,disk_boundary<D, ScalarT>>, "TODO: not yet implemented");
    }
    
};
