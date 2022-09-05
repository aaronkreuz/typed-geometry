#include <nexus/app.hh>
#include <nexus/test.hh>

#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <tuple>
#include <vector>

#if defined(TG_IMPLEMENTATION_REPORT)

#include <typed-geometry/tg-std.hh>

namespace
{

template <class T>
using try_print = decltype(std::declval<std::ostream&>() << std::declval<T>());

template <class T>
using try_equal = decltype(std::declval<T>() == std::declval<T>() || std::declval<T>() != std::declval<T>());

template <class T>
using try_less = decltype(std::map<T, int>().find(std::declval<T>()));

template <class T>
using try_hash = decltype(std::hash<T>()(std::declval<T const&>()));

template <class T>
using try_any_point = decltype(any_point(std::declval<T const&>()));

template <class T>
using try_project_pos2 = decltype(project(tg::pos2(), std::declval<T const&>()));

template <class T>
using try_contains_pos2 = decltype(contains(std::declval<T const&>(), tg::pos2()));

template <class T>
using try_project_pos3 = decltype(project(tg::pos3(), std::declval<T const&>()));

template <class T>
using try_contains_pos3 = decltype(contains(std::declval<T const&>(), tg::pos3()));

template <class T>
using try_uniform = decltype(uniform(std::declval<tg::rng>(), std::declval<T const&>()));

template <class T>
using try_aabb_of = decltype(aabb_of(std::declval<T const&>()));

template <class T>
using try_centroid_of = decltype(centroid_of(std::declval<T const&>()));

template <class T>
using try_length_of = decltype(length(std::declval<T const&>()));

template <class T>
using try_area_of = decltype(area_of(std::declval<T const&>()));

template <class T>
using try_volume_of = decltype(volume_of(std::declval<T const&>()));

template <class T>
using try_perimeter_of = decltype(perimeter_of(std::declval<T const&>()));

// TEST: Double template
template <class T, class F>
using try_intersects = decltype(intersects(std::declval<T const&>(), std::declval<F const&>()));

template <class T>
using try_closest_ray2_intersect_of = decltype(closest_intersection_parameter(tg::ray2(), std::declval<T const&>()));

template <class T>
using try_closest_ray3_intersect_of = decltype(closest_intersection_parameter(tg::ray3(), std::declval<T const&>()));

template <class T>
using try_intersects_line3_of = decltype(intersects(std::declval<T const&>(), tg::line3()));

template <class T>
using try_intersects_ray3_of = decltype(intersects(std::declval<T const&>(), tg::ray3()));

template <class T>
using try_intersects_segment2_of = decltype(intersects(std::declval<T const&>(), tg::aabb2()));

template <class T>
using try_intersects_aabb2_of = decltype(intersects(std::declval<T const&>(), tg::aabb2()));

template <class T>
using try_intersects_aabb3_of = decltype(intersects(std::declval<T const&>(), tg::aabb3()));

template <class T>
using try_intersects_segment3_of = decltype(intersects(std::declval<T const&>(), tg::segment3()));

template <class T>
using try_intersects_sphere3_of = decltype(intersects(std::declval<T const&>(), tg::sphere3()));

template <class T>
using try_intersects_box3_of = decltype(intersects(std::declval<T const&>(), tg::box3()));

template <class T>
using try_intersects_capsule3_of = decltype(intersects(std::declval<T const&>(), tg::capsule3()));

template <class T>
using try_intersects_cone3_of = decltype(intersects(std::declval<T const&()>, tg::cone3()));

template <class T>
using try_intersects_cylinder3_of = decltype(intersects(std::declval<T const&>(), tg::cylinder3()));

template <class T>
using try_intersects_ellipse3_of = decltype(intersects(std::declval<T const&>(), tg::ellipse3()));

template <class T>
using try_intersects_halfspace3_of = decltype(intersects(std::declval<T const&>(), tg::halfspace3()));

template <class T>
using try_intersects_hemisphere3_of = decltype(intersects(std::declval<T const&>(), tg::hemisphere3()));

template <class T>
using try_intersects_triangle3_of = decltype(intersects(std::declval<T const&>(), tg::triangle3()));

template <class T>
using try_intersects_plane3_of = decltype(intersects(std::declval<T const&>(), tg::plane3()));

template <class T>
using try_intersects_tube3_of = decltype(intersects(std::declval<T const&>(), tg::tube3()));

template <class T>
using try_intersects_sphere2in3_of = decltype(intersects(std::declval<T const&>(), tg::sphere2in3()));

template <class T>
using try_solid_of = decltype(solid_of(std::declval<T const&>()));

template <class T>
using try_distance_line3_of = decltype(distance(std::declval<T const&>(), tg::line3()));

template <class T>
using try_distance_ray3_of = decltype(distance(std::declval<T const&>(), tg::ray3()));

template <class T>
using try_distance_segment3_of = decltype(distance(std::declval<T const&>(), tg::segment3()));

template <class T>
using try_distance_aabb2_of = decltype(distance(std::declval<T const&>(), tg::aabb2()));

template <class T>
using try_distance_aabb3_of = decltype(distance(std::declval<T const&>(), tg::aabb3()));

template <class T>
using try_distance_sphere3_of = decltype(distance(std::declval<T const&>(), tg::sphere3()));

template <class T>
using try_distance_box3_of = decltype(distance(std::declval<T const&>(), tg::box3()));

template <class T>
using try_distance_capsule3_of = decltype(distance(std::declval<T const&>(), tg::capsule3()));

template <class T>
using try_distance_cone3_of = decltype(distance(std::declval<T const&()>, tg::cone3()));

template <class T>
using try_distance_cylinder3_of = decltype(distance(std::declval<T const&>(), tg::cylinder3()));

template <class T>
using try_distance_ellipse3_of = decltype(distance(std::declval<T const&>(), tg::ellipse3()));

template <class T>
using try_distance_halfspace3_of = decltype(distance(std::declval<T const&>(), tg::halfspace3()));

template <class T>
using try_distance_hemisphere3_of = decltype(distance(std::declval<T const&>(), tg::hemisphere3()));

template <class T>
using try_distance_triangle3_of = decltype(distance(std::declval<T const&>(), tg::triangle3()));

template <class T>
using try_distance_plane3_of = decltype(distance(std::declval<T const&>(), tg::plane3()));

template <class T>
using try_distance_tube3_of = decltype(distance(std::declval<T const&>(), tg::tube3()));

template <class T>
using try_distance_sphere2in3_of = decltype(distance(std::declval<T const&>(), tg::sphere2in3()));

template <class T, class F>
using try_distance_sqr = decltype(distance_sqr(std::declval<T const&>(), std::declval<F const&>()));

template <class ObjT>
void test_single_object_type(std::string name)
{
    static auto constexpr domainD = tg::object_traits<ObjT>::domain_dimension;
    static auto constexpr objectD = tg::object_traits<ObjT>::object_dimension;
    static auto constexpr solidD = []
    {
        if constexpr (tg::can_apply<try_solid_of, ObjT>)
            return tg::object_traits<try_solid_of<ObjT>>::object_dimension;
        return objectD;
    }(); // ternary constexpr of solid domain with fallback to object domain

    if constexpr (!std::is_default_constructible_v<ObjT>)
        std::cerr << "cannot default construct tg::" << name << std::endl;

    if constexpr (tg::can_apply<try_print, ObjT>)
    {
        std::stringstream ss;
        ss << ObjT{};
        const auto s = ss.str();
        const auto test_name = name;
        if (name.size() >= 7 && std::string_view(name).substr(0, 7) == "pyramid")
            name += ")"; // closing brace for nested types
        if (s.find(test_name) == std::string::npos)
            std::cerr << "possible error in outputting tg::" << name << ": '" << s << "'" << std::endl;
    }
    else
        std::cerr << "cannot print tg::" << name << std::endl;

    if constexpr (!tg::can_apply<try_equal, ObjT>)
        std::cerr << "equality not implemented for tg::" << name << std::endl;

    // TODO: somehow doesnt work?
    if constexpr (!tg::can_apply<try_less, ObjT>)
        std::cerr << "std::less not specialized for tg::" << name << std::endl;

    if constexpr (!tg::can_apply<try_hash, ObjT>)
        std::cerr << "std::hash not specialized for tg::" << name << std::endl;

    if constexpr (!tg::can_apply<try_any_point, ObjT>)
        std::cerr << "no any_point(tg::" << name << ")" << std::endl;

    if constexpr (domainD == 2)
    {
        if constexpr (!tg::can_apply<try_project_pos2, ObjT>)
        {
            if (!(name.size() >= 7 && std::string_view(name).substr(0, 7) == "ellipse")) // project(ellipse) is not planned
                std::cerr << "no project(tg::pos2, tg::" << name << ")" << std::endl;
        }

        if constexpr (!tg::can_apply<try_contains_pos2, ObjT>)
            std::cerr << "no contains(tg::" << name << ", tg::pos2)" << std::endl;
    }
    else if constexpr (domainD == 3)
    {
        if constexpr (!tg::can_apply<try_project_pos3, ObjT>)
        {
            if (!(name.size() >= 7 && std::string_view(name).substr(0, 7) == "ellipse")) // project(ellipse) is not planned
                std::cerr << "no project(tg::pos3, tg::" << name << ")" << std::endl;
        }

        if constexpr (!tg::can_apply<try_contains_pos3, ObjT>)
            std::cerr << "no contains(tg::" << name << ", tg::pos3)" << std::endl;
    }
    else
        static_assert(tg::always_false_v<domainD>, "not implemented");

    // operations for finite objects
    if constexpr (tg::object_traits<ObjT>::is_finite)
    {
        if constexpr (!tg::can_apply<try_uniform, ObjT>)
            std::cerr << "no uniform(tg::rng, tg::" << name << ")" << std::endl;

        if constexpr (!tg::can_apply<try_aabb_of, ObjT>)
            std::cerr << "no aabb_of(tg::" << name << ")" << std::endl;

        if constexpr (!tg::can_apply<try_centroid_of, ObjT>)
            std::cerr << "no centroid_of(tg::" << name << ")" << std::endl;

        if constexpr (objectD == 1)
        {
            if constexpr (solidD == 1 && !tg::can_apply<try_length_of, ObjT>)
                std::cerr << "no length(tg::" << name << ")" << std::endl;

            if constexpr (solidD != 1 && !tg::can_apply<try_perimeter_of, ObjT>)
                std::cerr << "no perimeter_of(tg::" << name << ")" << std::endl;
        }
        else if constexpr (objectD == 2)
        {
            if constexpr (!tg::can_apply<try_area_of, ObjT>)
                std::cerr << "no area_of(tg::" << name << ")" << std::endl;

            if constexpr (solidD == 2 && !tg::can_apply<try_perimeter_of, ObjT>)
                std::cerr << "no perimeter_of(tg::" << name << ")" << std::endl;
        }
        else if constexpr (objectD == 3)
        {
            if constexpr (!tg::can_apply<try_volume_of, ObjT>)
                std::cerr << "no volume_of(tg::" << name << ")" << std::endl;

            if constexpr (solidD == 3 && !tg::can_apply<try_area_of, ObjT>)
                std::cerr << "no area_of(tg::" << name << ")" << std::endl;
        }
        else
            static_assert(tg::always_false_v<objectD>, "not implemented");
    }

    // ray intersections
    if constexpr (objectD >= domainD - 1)
    {
        if constexpr (domainD == 2 && !tg::can_apply<try_closest_ray2_intersect_of, ObjT>)
            std::cerr << "no closest_intersection_parameter(tg::ray2, tg::" << name << ")" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_closest_ray3_intersect_of, ObjT>)
            std::cerr << "no closest_intersection_parameter(tg::ray3, tg::" << name << ")" << std::endl;

        if constexpr (domainD == 2 && !tg::can_apply<try_intersects_aabb2_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::aabb2)" << std::endl;
        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_aabb3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::aabb3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_box3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::box3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_segment3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::segment3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_sphere3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::sphere3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_capsule3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::capsule3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_cone3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::cone3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_cylinder3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::cylinder3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_ellipse3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::ellipse3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_halfspace3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::halfspace3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_hemisphere3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::hemisphere3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_triangle3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::triangle3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_plane3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::plane3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_tube3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::tube3)" << std::endl;

        if constexpr (domainD == 3 && !tg::can_apply<try_intersects_sphere2in3_of, ObjT>)
            std::cerr << "no intersects(tg::" << name << ", tg::sphere2in3)" << std::endl;

        // TODO: more
    }
}

template <template <int, class> class ObjT>
void test_object_type(std::string const& basename)
{
    test_single_object_type<ObjT<2, float>>(basename + "2");
    test_single_object_type<ObjT<3, float>>(basename + "3");
}
template <template <int, class, class> class ObjT>
void test_object_type_boundary(std::string const& basename)
{
    test_single_object_type<ObjT<2, float, tg::default_object_tag>>(basename + "2");
    test_single_object_type<ObjT<3, float, tg::default_object_tag>>(basename + "3");
    test_single_object_type<ObjT<2, float, tg::boundary_tag>>(basename + "2_boundary");
    test_single_object_type<ObjT<3, float, tg::boundary_tag>>(basename + "3_boundary");
}
template <template <int, class, class> class ObjT>
void test_object_type_3_boundary(std::string const& basename)
{
    test_single_object_type<ObjT<3, float, tg::default_object_tag>>(basename + "3");
    test_single_object_type<ObjT<3, float, tg::boundary_tag>>(basename + "3_boundary");
}
template <template <int, class, class> class ObjT>
void test_object_type_boundary_caps(std::string const& basename)
{
    test_single_object_type<ObjT<2, float, tg::default_object_tag>>(basename + "2");
    test_single_object_type<ObjT<3, float, tg::default_object_tag>>(basename + "3");
    test_single_object_type<ObjT<2, float, tg::boundary_tag>>(basename + "2_boundary");
    test_single_object_type<ObjT<3, float, tg::boundary_tag>>(basename + "3_boundary");
    test_single_object_type<ObjT<2, float, tg::boundary_no_caps_tag>>(basename + "2_boundary_no_caps");
    test_single_object_type<ObjT<3, float, tg::boundary_no_caps_tag>>(basename + "3_boundary_no_caps");
}
template <template <int, class, class> class ObjT>
void test_object_type_3_boundary_caps(std::string const& basename)
{
    test_single_object_type<ObjT<3, float, tg::default_object_tag>>(basename + "3");
    test_single_object_type<ObjT<3, float, tg::boundary_tag>>(basename + "3_boundary");
    test_single_object_type<ObjT<3, float, tg::boundary_no_caps_tag>>(basename + "3_boundary_no_caps");
}
template <template <int, class, int, class> class ObjT>
void test_object_type_23_boundary(std::string const& basename)
{
    test_single_object_type<ObjT<2, float, 2, tg::default_object_tag>>(basename + "2");
    test_single_object_type<ObjT<2, float, 3, tg::default_object_tag>>(basename + "2in3");
    test_single_object_type<ObjT<3, float, 3, tg::default_object_tag>>(basename + "3");
    test_single_object_type<ObjT<2, float, 2, tg::boundary_tag>>(basename + "2_boundary");
    test_single_object_type<ObjT<2, float, 3, tg::boundary_tag>>(basename + "2in3_boundary");
    test_single_object_type<ObjT<3, float, 3, tg::boundary_tag>>(basename + "3_boundary");
}
template <template <class, class> class ObjT, class NestedT>
void test_object_type_nested_boundary_caps(std::string const& basename, std::string const& nestedName)
{
    test_single_object_type<ObjT<NestedT, tg::default_object_tag>>(basename + "(" + nestedName);
    test_single_object_type<ObjT<NestedT, tg::boundary_tag>>(basename + "_boundary(" + nestedName);
    test_single_object_type<ObjT<NestedT, tg::boundary_no_caps_tag>>(basename + "_boundary_no_caps(" + nestedName);
}
}

TEST("implementation report")
{
    // objects
    test_object_type<tg::line>("line");
    test_object_type<tg::ray>("ray");
    test_object_type<tg::segment>("segment");
    test_object_type<tg::triangle>("triangle");
    test_object_type<tg::quad>("quad");
    test_object_type<tg::halfspace>("halfspace");
    test_object_type<tg::plane>("plane");

    test_object_type_boundary<tg::aabb>("aabb");
    test_object_type_boundary<tg::inf_cone>("inf_cone");
    test_object_type_boundary<tg::inf_cylinder>("inf_cylinder");

    test_object_type_boundary_caps<tg::hemisphere>("hemisphere");

    test_object_type_3_boundary<tg::capsule>("capsule");
    test_object_type_3_boundary_caps<tg::cylinder>("cylinder");

    test_object_type_23_boundary<tg::box>("box");
    test_object_type_23_boundary<tg::ellipse>("ellipse");
    test_object_type_23_boundary<tg::sphere>("sphere");

    test_object_type_nested_boundary_caps<tg::pyramid, tg::sphere2in3>("pyramid", "sphere2in3");
    test_object_type_nested_boundary_caps<tg::pyramid, tg::box2in3>("pyramid", "box2in3");
    test_object_type_nested_boundary_caps<tg::pyramid, tg::triangle3>("pyramid", "triangle3");
    // test_object_type_nested_boundary_caps<tg::pyramid, tg::quad3>("pyramid", "quad3");
}

template <class ObjT>
std::vector<std::pair<std::string, bool>> test_single_object_type_intersects3D_tex(std::string name)
{
    static auto constexpr domainD = tg::object_traits<ObjT>::domain_dimension;
    static auto constexpr objectD = tg::object_traits<ObjT>::object_dimension;

    std::vector<std::pair<std::string, bool>> intersect_vals;

    if constexpr (domainD != 3)
        return intersect_vals;

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_segment3_of, ObjT>)
        intersect_vals.push_back({"segment3", false});
    else
        intersect_vals.push_back({"segment3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_line3_of, ObjT>)
        intersect_vals.push_back({"line3", false});
    else
        intersect_vals.push_back({"line3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_ray3_of, ObjT>)
        intersect_vals.push_back({"ray3", false});
    else
        intersect_vals.push_back({"ray3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_box3_of, ObjT>)
        intersect_vals.push_back({"box3", false});
    else
        intersect_vals.push_back({"box3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_sphere3_of, ObjT>)
        intersect_vals.push_back({"sphere3", false});
    else
        intersect_vals.push_back({"sphere3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_aabb3_of, ObjT>)
        intersect_vals.push_back({"aabb3", false});
    else
        intersect_vals.push_back({"aabb3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_capsule3_of, ObjT>)
        intersect_vals.push_back({"capsule3", false});
    else
        intersect_vals.push_back({"capsule3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_cone3_of, ObjT>)
        intersect_vals.push_back({"cone3", false});
    else
        intersect_vals.push_back({"cone3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_cylinder3_of, ObjT>)
        intersect_vals.push_back({"cylinder3", false});
    else
        intersect_vals.push_back({"cylinder3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_ellipse3_of, ObjT>)
        intersect_vals.push_back({"ellipse3", false});
    else
        intersect_vals.push_back({"ellipse3", true});

    if constexpr (!tg::can_apply<try_intersects_halfspace3_of, ObjT>)
        intersect_vals.push_back({"halfspace3", false});
    else
        intersect_vals.push_back({"halfspace3", true});

    if constexpr (!tg::can_apply<try_intersects_hemisphere3_of, ObjT>)
        intersect_vals.push_back({"hemisphere3", false});
    else
        intersect_vals.push_back({"hemisphere3", true});

    if constexpr (!tg::can_apply<try_intersects_triangle3_of, ObjT>)
        intersect_vals.push_back({"triangle3", false});
    else
        intersect_vals.push_back({"triangle3", true});

    if constexpr (!tg::can_apply<try_intersects_plane3_of, ObjT>)
        intersect_vals.push_back({"plane3", false});
    else
        intersect_vals.push_back({"plane3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_tube3_of, ObjT>)
        intersect_vals.push_back({"tube3", false});
    else
        intersect_vals.push_back({"tube3", true});

    if constexpr (domainD == 3 && !tg::can_apply<try_intersects_sphere2in3_of, ObjT>)
        intersect_vals.push_back({"sphere2in3", false});
    else
        intersect_vals.push_back({"sphere2in3", true});

    return intersect_vals;
}

template <class ObjT>
std::vector<std::pair<std::string, bool>> test_single_object_type_distance3D_tex(std::string name)
{
    static auto constexpr domainD = tg::object_traits<ObjT>::domain_dimension;
    static auto constexpr objectD = tg::object_traits<ObjT>::object_dimension;

    std::vector<std::pair<std::string, bool>> distance_vals;

    if constexpr (domainD != 3)
        return distance_vals;

    if constexpr (!tg::can_apply<try_distance_segment3_of, ObjT>)
        distance_vals.push_back({"segment3", false});
    else
        distance_vals.push_back({"segment3", true});

    if constexpr (!tg::can_apply<try_distance_line3_of, ObjT>)
        distance_vals.push_back({"line3", false});
    else
        distance_vals.push_back({"line3", true});

    if constexpr (!tg::can_apply<try_distance_ray3_of, ObjT>)
        distance_vals.push_back({"ray3", false});
    else
        distance_vals.push_back({"ray3", true});

    if constexpr (!tg::can_apply<try_distance_box3_of, ObjT>)
        distance_vals.push_back({"box3", false});
    else
        distance_vals.push_back({"box3", true});

    if constexpr (!tg::can_apply<try_distance_sphere3_of, ObjT>)
        distance_vals.push_back({"sphere3", false});
    else
        distance_vals.push_back({"sphere3", true});

    if constexpr (!tg::can_apply<try_distance_aabb3_of, ObjT>)
        distance_vals.push_back({"aabb3", false});
    else
        distance_vals.push_back({"aabb3", true});

    if constexpr (!tg::can_apply<try_distance_capsule3_of, ObjT>)
        distance_vals.push_back({"capsule3", false});
    else
        distance_vals.push_back({"capsule3", true});

    if constexpr (!tg::can_apply<try_distance_cone3_of, ObjT>)
        distance_vals.push_back({"cone3", false});
    else
        distance_vals.push_back({"cone3", true});

    if constexpr (!tg::can_apply<try_distance_cylinder3_of, ObjT>)
        distance_vals.push_back({"cylinder3", false});
    else
        distance_vals.push_back({"cylinder3", true});

    if constexpr (!tg::can_apply<try_distance_ellipse3_of, ObjT>)
        distance_vals.push_back({"ellipse3", false});
    else
        distance_vals.push_back({"ellipse3", true});

    if constexpr (!tg::can_apply<try_distance_halfspace3_of, ObjT>)
        distance_vals.push_back({"halfspace3", false});
    else
        distance_vals.push_back({"halfspace3", true});

    if constexpr (!tg::can_apply<try_distance_hemisphere3_of, ObjT>)
        distance_vals.push_back({"hemisphere3", false});
    else
        distance_vals.push_back({"hemisphere3", true});

    if constexpr (!tg::can_apply<try_distance_triangle3_of, ObjT>)
        distance_vals.push_back({"triangle3", false});
    else
        distance_vals.push_back({"triangle3", true});

    if constexpr (!tg::can_apply<try_distance_plane3_of, ObjT>)
        distance_vals.push_back({"plane3", false});
    else
        distance_vals.push_back({"plane3", true});

    if constexpr (!tg::can_apply<try_distance_tube3_of, ObjT>)
        distance_vals.push_back({"tube3", false});
    else
        distance_vals.push_back({"tube3", true});

    if constexpr (!tg::can_apply<try_distance_sphere2in3_of, ObjT>)
        distance_vals.push_back({"sphere2in3", false});
    else
        distance_vals.push_back({"sphere2in3", true});

    return distance_vals;
}

template <class ObjT>
std::vector<std::pair<std::string, bool>> test_single_object_type_intersects2D_tex(std::string name)
{
    static auto constexpr domainD = tg::object_traits<ObjT>::domain_dimension;
    static auto constexpr objectD = tg::object_traits<ObjT>::object_dimension;

    std::vector<std::pair<std::string, bool>> intersects_vals;

    // CHECK for domains
    if constexpr (domainD != 2 && objectD != 2)
        return intersects_vals;

    if constexpr (!tg::can_apply<try_intersects, ObjT, tg::segment2>)
        intersects_vals.push_back({"segment2", false});
    else
        intersects_vals.push_back({"segment2", true});

    if constexpr (!tg::can_apply<try_intersects, ObjT, tg::ray2>)
        intersects_vals.push_back({"ray2", false});
    else
        intersects_vals.push_back({"ray2", true});

    if constexpr (!tg::can_apply<try_intersects, ObjT, tg::line2>)
        intersects_vals.push_back({"line2", false});
    else
        intersects_vals.push_back({"line2", true});

    if constexpr (!tg::can_apply<try_intersects, ObjT, tg::circle2>)
        intersects_vals.push_back({"circle2", false});
    else
        intersects_vals.push_back({"circle2", true});

    if constexpr (!tg::can_apply<try_intersects, ObjT, tg::box2>)
        intersects_vals.push_back({"box2", false});
    else
        intersects_vals.push_back({"box2", true});

    if constexpr (!tg::can_apply<try_intersects, ObjT, tg::triangle2>)
        intersects_vals.push_back({"triangle2", false});
    else
        intersects_vals.push_back({"triangle2", true});

    if constexpr (!tg::can_apply<try_intersects, ObjT, tg::aabb2>)
        intersects_vals.push_back({"aabb2", false});
    else
        intersects_vals.push_back({"aabb2", true});

    return intersects_vals;
}

template <class ObjT>
std::vector<std::pair<std::string, bool>> test_single_object_type_distance_sqr3D_tex(std::string name)
{
    static auto constexpr domainD = tg::object_traits<ObjT>::domain_dimension;
    static auto constexpr objectD = tg::object_traits<ObjT>::object_dimension;

    std::vector<std::pair<std::string, bool>> distance_sqr_vals;

    if constexpr (domainD != 3)
        return distance_sqr_vals;

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::segment3>)
        distance_sqr_vals.push_back({"segment3", false});
    else
        distance_sqr_vals.push_back({"segment3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::line3>)
        distance_sqr_vals.push_back({"line3", false});
    else
        distance_sqr_vals.push_back({"line3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::ray3>)
        distance_sqr_vals.push_back({"ray3", false});
    else
        distance_sqr_vals.push_back({"ray3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::box3>)
        distance_sqr_vals.push_back({"box3", false});
    else
        distance_sqr_vals.push_back({"box3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::sphere3>)
        distance_sqr_vals.push_back({"sphere3", false});
    else
        distance_sqr_vals.push_back({"sphere3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::aabb3>)
        distance_sqr_vals.push_back({"aabb3", false});
    else
        distance_sqr_vals.push_back({"aabb3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::capsule3>)
        distance_sqr_vals.push_back({"capsule3", false});
    else
        distance_sqr_vals.push_back({"capsule3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::cone3>)
        distance_sqr_vals.push_back({"cone3", false});
    else
        distance_sqr_vals.push_back({"cone3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::cylinder3>)
        distance_sqr_vals.push_back({"cylinder3", false});
    else
        distance_sqr_vals.push_back({"cylinder3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::ellipse3>)
        distance_sqr_vals.push_back({"ellipse3", false});
    else
        distance_sqr_vals.push_back({"ellipse3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::halfspace3>)
        distance_sqr_vals.push_back({"halfspace3", false});
    else
        distance_sqr_vals.push_back({"halfspace3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::hemisphere3>)
        distance_sqr_vals.push_back({"hemisphere3", false});
    else
        distance_sqr_vals.push_back({"hemisphere3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::triangle3>)
        distance_sqr_vals.push_back({"triangle3", false});
    else
        distance_sqr_vals.push_back({"triangle3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::plane3>)
        distance_sqr_vals.push_back({"plane3", false});
    else
        distance_sqr_vals.push_back({"plane3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::tube3>)
        distance_sqr_vals.push_back({"tube3", false});
    else
        distance_sqr_vals.push_back({"tube3", true});

    if constexpr (!tg::can_apply<try_distance_sqr, ObjT, tg::sphere2in3>)
        distance_sqr_vals.push_back({"sphere2in3", false});
    else
        distance_sqr_vals.push_back({"sphere2in3", true});

    return distance_sqr_vals;
}


// TODO: Function renaming?
std::vector<bool> make_mask_matrix(std::vector<std::pair<std::string, bool>> const& data, std::vector<std::pair<std::string, std::string>> const& not_impl_pairs)
{
    auto const contains_pair = [&](std::string const& a, std::string const& b) -> bool
    {
        for (auto& z : not_impl_pairs)
        {
            if ((a == z.first && b == z.second) || (a == z.second && b == z.first))
                return true;
        }

        return false;
    };

    std::vector<bool> should_not_impl;

    for (auto& x : data)
        for (auto& y : data)
        {
            if (contains_pair(x.first, y.first))
            {
                should_not_impl.push_back(true);
                continue;
            }

            should_not_impl.push_back(false);
        }

    return should_not_impl;
}

// TODO: Experimental Meta-Programming
template <typename... input_t>
using tuple_cat_t = decltype(std::tuple_cat(std::declval<input_t>()...));

template <class Head, class... Tail>
struct help_expander_t
{
    using type = std::tuple<std::pair<Head, Tail>...>;
};

template <class Head, class... Tail>
using help_expander = typename help_expander_t<Head, Tail...>::type;


template <class... Args1>
struct type_table_cols_t
{
    template <class... Args2>
    struct type_table_rows_t
    {
        using type = tuple_cat_t<help_expander<Args1, Args2...>...>;
    };
};

template <class... Ts>
struct type_table_t
{
    using type = typename type_table_cols_t<Ts...>::template type_table_rows_t<Ts...>::type;
};

// using type_table_distance
//     = type_table_t<tg::segment3, tg::line3, tg::ray3, tg::box3, tg::sphere3, tg::aabb3, tg::capsule3, tg::cone3, tg::cylinder3, tg::ellipse3, tg::halfspace3, tg::hemisphere3, tg::triangle3, tg::plane3, tg::tube3, tg::sphere2in3>::type;

using types_table_distance_exp
    = std::tuple<tg::segment3, tg::line3, tg::ray3, tg::box3, tg::sphere3, tg::aabb3, tg::capsule3, tg::cone3, tg::cylinder3, tg::ellipse3, tg::halfspace3, tg::hemisphere3, tg::triangle3, tg::plane3, tg::tube3, tg::sphere2in3>;

// using type_table_2D = type_table_t<tg::segment2, tg::line2, tg::ray2, tg::circle2, tg::box2, tg::triangle2, tg::aabb2>::type;

template <class T0, class T1>
bool handle_pair_distance_sqr(T0 const& t0, T1 const& t1)
{
    bool x;

    if (!tg::can_apply<try_distance_sqr, T0, T1>)
        x = false;
    else
        x = true;

    std::cout << x << std::endl;

    return x;
}

template <class Tuple, class T0>
void apply_expander(T0 const& type_pair)
{
    std::apply([](auto... tuple_args) { (handle_pair_distance_sqr(T0{}, tuple_args), ...); }, types_table_distance_exp{});
}

APP("ImplReport_LATEX")
{
    // List of not-impl pairs -> build matrix from list
    std::vector<std::pair<std::string, std::string>> should_not_impl_intersects_pairs = {
        {"segment3", "segment3"}, //
        {"segment3", "line3"},    //
        {"segment3", "ray3"},     //
        {"line3", "line3"},       //
        {"line3", "ray3"},        //
        {"ray3", "ray3"}          //
    };

    std::vector<std::pair<std::string, std::string>> should_not_impl_distance_pairs = {
        {"line3", "halfspace3"}, //
        {"line3", "plane3"}      //
    };

    std::vector<std::pair<std::string, std::string>> should_not_impl_distance_sqr_pairs = {};

    std::vector<std::pair<std::string, std::string>> should_not_impl_intersects2D_pairs = {};

    // file generation
    std::ofstream("impl_report.tex");
    std::fstream f;
    f.open("impl_report.tex", std::ios::trunc);
    f.close();
    f.open("impl_report.tex", std::ios::out);

    // header
    f << "\\documentclass{scrartcl}\n";
    f << "\\usepackage[utf8]{inputenc}\n";
    f << "\\usepackage[table]{xcolor}\n";
    f << "\\usepackage{graphicx}\n";
    f << "\\usepackage{multirow}\n";
    f << "\\usepackage{geometry}\n";
    f << "\\geometry{\n"
      << "a4paper,\n"
      << "left=10mm,\n"
      << "right=10mm,\n"
      << "top=20mm,\n"
      << "}\n";
    f << "\\usepackage[headsepline]{scrlayer-scrpage}\n";
    f << "\\pagestyle{scrheadings}\n";
    f << "\\clearpairofpagestyles\n";
    f << "\\chead{IMPL REPORT}\n";
    f << "\\ihead{\\today}\n";
    f << "\\setlength{\\arrayrulewidth}{0.5mm}\n";
    f << "\\renewcommand{\\arraystretch}{1.5}\n" << std::endl;
    f << "\\newcolumntype{s}{>{\\columncolor[HTML]{E6E6E6}} p{2.3cm}}\n" << std::endl;
    f << "\\newcolumntype{e}{>{\\columncolor[HTML]{E6E6E6}} p{3cm}}\n" << std::endl;
    f << "\\newcommand{\\nondefCol}[1]{\\cellcolor[HTML]{FF3F16}}\n";
    f << "\\newcommand{\\defCol}[1]{\\cellcolor[HTML]{97E26F}}\n";
    f << "\\newcommand{\\notplannedCol}[1]{\\cellcolor[HTML]{3B3B3B}}\n" << std::endl;
    f << "\\title{IMPL REPORT}\n";
    f << "\\begin{document}\n" << std::endl;
    f.close();

    // test tables

    // legend
    f.open("impl_report.tex", std::ios::out | std::ios::app);
    f << "\\begin{tabular}{|e|e|e|} \\hline \n";
    f << "\\cellcolor[HTML]{E6E6E6} DEFINED & \\cellcolor[HTML]{E6E6E6} UNDEFINED & \\cellcolor[HTML]{E6E6E6} SHOULD NOT \\\\ \n";
    f << "\\defCol{} & \\nondefCol{} & \\notplannedCol{} \\\\ \\hline \n";
    f << "\\end{tabular}" << std::endl;
    f << "\\vspace{1.5cm} \n" << std::endl;

    f.close();

    // Func writing tabular based on arguments
    auto const write_tabular
        = [&](std::vector<std::pair<std::string, bool>> matrix, float cell_width, std::string tabular_name, std::vector<bool> should_not_impl, int nbr_elements)
    {
        f.open("impl_report.tex", std::ios::out | std::ios::app);
        f << "\\begin{tabular}{|s|"; //{" << cell_width_str << "\\linewidth}|";

        for (auto i = 0; i < int(nbr_elements); i++)
            f << "p{" << std::to_string(cell_width) << "\\linewidth}|";

        f << "} \\hline" << std::endl;

        // header row
        f << "\\cellcolor[HTML]{FF9D88} " << tabular_name;

        for (auto i = 0; i < nbr_elements; i++)
        {
            if (cell_width > 0.15)
                f << "& \\cellcolor[HTML]{E6E6E6} " << matrix[i].first;

            else
                f << "& \\cellcolor[HTML]{E6E6E6} "
                  << "\\rotatebox{90}{" << matrix[i].first << "}";
        }
        f << " \\\\ \\hline" << std::endl;

        // data rows
        for (auto i = 0; i < nbr_elements; i++)
        {
            auto& data = matrix[i];
            int offset = nbr_elements * i;

            f << "\\cellcolor[HTML]{E6E6E6} " << matrix[offset + i].first << " ";

            for (auto row_it = 0; row_it < nbr_elements; row_it++)
            {
                if (matrix[offset + row_it].second)
                    f << "& \\defCol{} ";
                else if (!matrix[offset + row_it].second && should_not_impl[offset + row_it])
                    f << "& \\notplannedCol{} ";
                else
                    f << "& \\nondefCol{} ";
            }

            f << "\\\\ \\hline" << std::endl;
        }

        // end of TABLE
        f << "\\end{tabular}" << std::endl;
        f << "\\newline" << std::endl;
        f << "\\vspace{1.5cm} \n" << std::endl;
        f.close();
    };

    // TABLE distance_sqr 3D

    auto segment3distance_sqr = test_single_object_type_distance_sqr3D_tex<tg::segment3>("segment3");

    // data matrix
    std::vector<std::pair<std::string, bool>> distance_sqr_matrix;

    // TODO: Experimental Meta-Programming Type
    // auto distance_sqr_init = T_distance_sqr();
    // auto length_tuple = std::tuple_size_v<T_distance_sqr>;
    // auto table_instance = type_table_distance();

    // auto const on_tuple = [&](auto&&... ps)
    // {
    //     if (!tg::can_apply<try_distance_sqr, decltype(ps.first), decltype(ps.second)>)
    //         distance_sqr_matrix.push_back({typeid(decltype(ps.first)).name, false});
    //     else
    //         distance_sqr_matrix.push_back({typeid(decltype(ps.first)).name, true});
    // };

    // std::apply([](auto... tuple_args) { (handle_pair_distance_sqr(tuple_args), ...); }, type_table_distance{});

    std::apply([](auto... tuple_args) { (apply_expander<types_table_distance_exp>(tuple_args), ...); }, types_table_distance_exp{});


    // auto const foo = [](auto&& t){
    //     test_single_object_type_distance_sqr3D_tex<std::decay_t<decltype(t)>>("");
    // };

    auto const get_distance_sqr_data = [&](std::vector<std::pair<std::string, bool>>& distance_sqr_data, std::string class_name) -> void
    {
        if (class_name == "segment3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::segment3>("segment3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }
        if (class_name == "line3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::line3>("line3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }
        if (class_name == "ray3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::line3>("ray3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }
        if (class_name == "box3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::box3>("box3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "sphere3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::sphere3>("sphere3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "aabb3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::aabb3>("aabb3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "capsule3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::capsule3>("capsule3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "cone3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::cone3>("cone3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "cylinder3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::cylinder3>("cylinder3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "ellipse3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::ellipse3>("ellipse3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "halfspace3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::halfspace3>("halfspace3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "hemisphere3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::hemisphere3>("hemisphere3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "triangle3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::triangle3>("triangle3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "plane3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::plane3>("plane3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "tube3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::tube3>("tube3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "sphere2in3")
        {
            auto vec = test_single_object_type_distance_sqr3D_tex<tg::sphere2in3>("sphere2in3");
            distance_sqr_data.insert(distance_sqr_data.end(), vec.begin(), vec.end());
            return;
        }

        std::cout << "ERROR: " << class_name << std::endl;
    };

    // fill up data matrix
    int index_dist_sqr = 0;
    for (const auto& x : segment3distance_sqr)
        get_distance_sqr_data(distance_sqr_matrix, x.first);

    float cell_width_dist_sqr = 0.5f / (segment3distance_sqr.size() + 1);
    std::string cell_width_dist_sqr_str = tg::to_string(cell_width_dist_sqr);

    // wrtie tabular distance_sqr 3D
    write_tabular(distance_sqr_matrix, cell_width_dist_sqr, "\\centering{distance sqr 3D}",
                  make_mask_matrix(segment3distance_sqr, should_not_impl_distance_sqr_pairs), segment3distance_sqr.size());


    // TABLE intersects 3D

    auto segment3intersects = test_single_object_type_intersects3D_tex<tg::segment3>("segment3");

    // data matrix
    std::vector<std::pair<std::string, bool>> intersects_matrix;

    auto const get_intersect_data = [&](std::vector<std::pair<std::string, bool>>& insec_data, std::string class_name) -> void
    {
        if (class_name == "segment3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::segment3>("segment3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }

        if (class_name == "ray3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::ray3>("ray3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "line3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::line3>("line3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "box3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::box3>("box3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "sphere3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::sphere3>("sphere3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "aabb3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::aabb3>("aabb3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "capsule3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::capsule3>("capsule3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "cone3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::cone3>("cone3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "cylinder3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::cylinder3>("cylinder3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "ellipse3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::ellipse3>("ellipse3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "halfspace3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::halfspace3>("halfspace3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "hemisphere3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::hemisphere3>("hemisphere3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "triangle3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::triangle3>("triangle3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "plane3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::plane3>("plane3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "tube3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::tube3>("tube3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "sphere2in3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::sphere2in3>("sphere2in3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
        if (class_name == "inf_cylinder3")
        {
            auto vec = test_single_object_type_intersects3D_tex<tg::inf_cylinder3>("inf_cylinder3");
            insec_data.insert(insec_data.end(), vec.begin(), vec.end());
        }
    };

    int index = 0;
    for (auto& x : segment3intersects)
    {
        // fill up intersects matrix
        get_intersect_data(intersects_matrix, x.first);
    }

    float cell_width = 0.5f / (segment3intersects.size() + 1);
    std::string cell_width_str = std::to_string(cell_width);

    // write tabular intersects 3D
    write_tabular(intersects_matrix, cell_width, "intersects 3D", make_mask_matrix(segment3intersects, should_not_impl_intersects_pairs),
                  segment3intersects.size());


    // TABLE distance 3D
    auto segment3distance = test_single_object_type_distance3D_tex<tg::segment3>("segment3");

    // data matrix
    std::vector<std::pair<std::string, bool>> distance_matrix;

    auto const get_distance_data = [&](std::vector<std::pair<std::string, bool>>& distance_data, std::string class_name) -> void
    {
        if (class_name == "segment3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::segment3>("segment3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }
        if (class_name == "line3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::line3>("line3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }
        if (class_name == "ray3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::ray3>("ray3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }
        if (class_name == "box3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::box3>("box3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "sphere3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::sphere3>("sphere3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "aabb3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::aabb3>("aabb3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "capsule3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::capsule3>("capsule3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "cone3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::cone3>("cone3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "cylinder3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::cylinder3>("cylinder3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "ellipse3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::ellipse3>("ellipse3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "halfspace3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::halfspace3>("halfspace3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "hemisphere3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::hemisphere3>("hemisphere3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "triangle3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::triangle3>("triangle3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "plane3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::plane3>("plane3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "tube3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::tube3>("tube3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        if (class_name == "sphere2in3")
        {
            auto vec = test_single_object_type_distance3D_tex<tg::sphere2in3>("sphere2in3");
            distance_data.insert(distance_data.end(), vec.begin(), vec.end());
            return;
        }

        std::cout << "ERROR: " << class_name << std::endl;
    };

    int index_dist = 0;
    for (auto& x : segment3distance)
    {
        get_distance_data(distance_matrix, x.first);
    }

    float cell_width_dist = 0.5f / (segment3distance.size() + 1);
    std::string cell_width_str_dist = std::to_string(cell_width_dist);

    // write tabular distance 3D
    write_tabular(distance_matrix, cell_width_dist, "distance", make_mask_matrix(segment3distance, should_not_impl_distance_pairs), segment3distance.size());

    // TABLE intersects 2D
    auto segment2intersects = test_single_object_type_intersects2D_tex<tg::segment2>("segment2");

    // data matrix
    std::vector<std::pair<std::string, bool>> intersects2D_matrix;

    auto const get_intersect2D_data = [&](std::vector<std::pair<std::string, bool>>& intersects2D_data, std::string class_name) -> void
    {
        if (class_name == "segment2")
        {
            auto vec = test_single_object_type_intersects2D_tex<tg::segment2>("segment2");
            intersects2D_data.insert(intersects2D_data.end(), vec.begin(), vec.end());
        }
        else if (class_name == "line2")
        {
            auto vec = test_single_object_type_intersects2D_tex<tg::line2>("line2");
            intersects2D_data.insert(intersects2D_data.end(), vec.begin(), vec.end());
        }
        else if (class_name == "ray2")
        {
            auto vec = test_single_object_type_intersects2D_tex<tg::ray2>("ray2");
            intersects2D_data.insert(intersects2D_data.end(), vec.begin(), vec.end());
        }
        else if (class_name == "aabb2")
        {
            auto vec = test_single_object_type_intersects2D_tex<tg::aabb2>("aabb2");
            intersects2D_data.insert(intersects2D_data.end(), vec.begin(), vec.end());
        }
        else if (class_name == "circle2")
        {
            auto vec = test_single_object_type_intersects2D_tex<tg::circle2>("circle2");
            intersects2D_data.insert(intersects2D_data.end(), vec.begin(), vec.end());
        }
        else if (class_name == "box2")
        {
            auto vec = test_single_object_type_intersects2D_tex<tg::box2>("box2");
            intersects2D_data.insert(intersects2D_data.end(), vec.begin(), vec.end());
        }
        else if (class_name == "triangle2")
        {
            auto vec = test_single_object_type_intersects2D_tex<tg::triangle2>("triangle2");
            intersects2D_data.insert(intersects2D_data.end(), vec.begin(), vec.end());
        }
        return;
    };

    auto index_intersects2D = 0;
    for (auto& x : segment2intersects)
    {
        get_intersect2D_data(intersects2D_matrix, x.first);
    }

    float cell_width_intersects2D = 0.5f / (segment2intersects.size() + 1);
    std::string cell_width_str_intersects2D = std::to_string(cell_width_intersects2D);

    // write tabular intersects 2D
    write_tabular(intersects2D_matrix, cell_width_intersects2D, "intersects 2D",
                  make_mask_matrix(segment2intersects, should_not_impl_intersects2D_pairs), segment2intersects.size());

    // end
    f.open("impl_report.tex", std::ios::out | std::ios::app);
    f << "\\end{document}" << std::endl;
    f.close();


    // compile
    std::system("pdflatex impl_report.tex");
}

#endif
