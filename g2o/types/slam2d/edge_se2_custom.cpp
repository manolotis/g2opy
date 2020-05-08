
#include "edge_se2_custom.h"

using namespace Eigen;

namespace g2o {


    EdgeSE2Custom::EdgeSE2Custom() :
            BaseBinaryEdge<3, SE2, VertexSE2, VertexSE2>() {
    }

    bool EdgeSE2Custom::read(std::istream &is) {
        Vector3d p;
        is >> p[0] >> p[1] >> p[2];
        _measurement.fromVector(p);
        _inverseMeasurement = measurement().inverse();
        for (int i = 0; i < 3; ++i)
            for (int j = i; j < 3; ++j) {
                is >> information()(i, j);
                if (i != j)
                    information()(j, i) = information()(i, j);
            }
        return true;
    }

    bool EdgeSE2Custom::write(std::ostream &os) const {
        Vector3d p = measurement().toVector();
        os << p.x() << " " << p.y() << " " << p.z();
        for (int i = 0; i < 3; ++i)
            for (int j = i; j < 3; ++j)
                os << " " << information()(i, j);
        return os.good();
    }

} // end namespace
