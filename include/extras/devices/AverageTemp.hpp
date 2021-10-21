#ifndef _AVERAGETEMP_HPP
#define _AVERAGETEMP_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief AverageTempInterface
   *
   * Maintains a binrary array in memory
   */

  interface AverageTempInterface {
    virtual void addTemperature(float value) pure;
    virtual float calculateTemperature() pure;
    virtual float lastCalculatedTemperature() const pure;
  };

  /**
   * @brief AverageTempInterface
   *
   * Maintains a binrary array in memory
   */

  using TemperatureArray = std::vector<float>;

  /**
   * Can be used to calcuale temperature on all available
   * temperatures but may require huge memory demands.
   */

  concrete class AverageTemp implements AverageTempInterface {
    TemperatureArray _temperatureArray;
    float _lastCalculatedReading = 0;

   public:
    virtual void addTemperature(float value) override {
      _temperatureArray.push_back(value);
    };

    virtual float calculateTemperature() override {
      float sum = 0.0;
      for (auto value : _temperatureArray) sum += value;
      _lastCalculatedReading = sum / _temperatureArray.size();
      return _lastCalculatedReading;
    };
    virtual float lastCalculatedTemperature() const override {
      return _lastCalculatedReading;
    }
  };

  /**
   * In order to keep track of one million readings
   * all readings have to pass through an instance
   * of this class.
   */

  concrete class AverageTempLast10 implements AverageTempInterface {
    std::vector<long> totalLastTen;
    float _lastCalculatedReading = 0;

   public:
    virtual void addTemperature(float value) override {
      if (totalLastTen.size() > 10) totalLastTen.erase(totalLastTen.begin());
      totalLastTen.push_back(value);
    }

    virtual float calculateTemperature() override {
      float sum = 0;
      for (auto value : totalLastTen) sum += value;
      _lastCalculatedReading = sum / totalLastTen.size();
      return sum / totalLastTen.size();
    }

    virtual float lastCalculatedTemperature() const override {
      return _lastCalculatedReading;
    }
  };

  /**
   * In order to keep track of one million readings (last ten)
   * all readings have to pass through an instance of this class,
   * (without the use of any memory storage).
   *
   */

  concrete class AverageTempLast10Optimized implements AverageTempInterface {
    std::vector<float> _lastTenReadings;
    float _runningLastTenTotal = 0;
    float _lastCalculatedTemperature = 0;
    int _totalReadings = 0;

   public:
    virtual void addTemperature(float value) override {
      _lastTenReadings.push_back(value);
      _runningLastTenTotal += value;
      _totalReadings++;
      if (_lastTenReadings.size() > 10) {
        float valueToSubtract = *_lastTenReadings.begin();
        _lastTenReadings.erase(_lastTenReadings.begin());
        _runningLastTenTotal -= valueToSubtract;
      }
    }

    virtual float calculateTemperature() override {
      if (_totalReadings > 10)
        _lastCalculatedTemperature = _runningLastTenTotal / 10;
      else
        _lastCalculatedTemperature = _runningLastTenTotal / _totalReadings;
      return _lastCalculatedTemperature;
    }

    virtual float lastCalculatedTemperature() const override {
      return _lastCalculatedTemperature;
    }
  };

}  // namespace extras

#endif  // _AVERAGETEMP_HPP
