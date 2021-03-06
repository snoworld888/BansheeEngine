//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#pragma once

#include "BsCorePrerequisites.h"
#include "Physics/BsDistanceJoint.h"
#include "Components/BsCJoint.h"

namespace bs 
{
	/** @addtogroup Components-Core
	 *  @{
	 */

	/**
	 * @copydoc	DistanceJoint
	 *
	 * @note	Wraps DistanceJoint as a Component.
	 */
	class BS_CORE_EXPORT BS_SCRIPT_EXPORT(m:Physics,n:DistanceJoint) CDistanceJoint : public CJoint
	{
	public:
		CDistanceJoint(const HSceneObject& parent);

		/** @copydoc DistanceJoint::getDistance */
		BS_SCRIPT_EXPORT(n:Distance,pr:getter)
		inline float getDistance() const;

		/** @copydoc DistanceJoint::getMinDistance */
		BS_SCRIPT_EXPORT(n:MinDistance,pr:getter)
		inline float getMinDistance() const;

		/** @copydoc DistanceJoint::setMinDistance */
		BS_SCRIPT_EXPORT(n:MinDistance,pr:setter)
		inline void setMinDistance(float value);

		/** @copydoc DistanceJoint::getMaxDistance */
		BS_SCRIPT_EXPORT(n:MaxDistance,pr:getter)
		inline float getMaxDistance() const;

		/** @copydoc DistanceJoint::setMaxDistance */
		BS_SCRIPT_EXPORT(n:MaxDistance,pr:setter)
		inline void setMaxDistance(float value);

		/** @copydoc DistanceJoint::getTolerance */
		BS_SCRIPT_EXPORT(n:Tolerance,pr:getter)
		inline float getTolerance() const;

		/** @copydoc DistanceJoint::setTolerance */
		BS_SCRIPT_EXPORT(n:Tolerance,pr:setter)
		inline void setTolerance(float value);

		/** @copydoc DistanceJoint::getSpring */
		BS_SCRIPT_EXPORT(n:Spring,pr:getter)
		inline Spring getSpring() const;

		/** @copydoc DistanceJoint::setSpring */
		BS_SCRIPT_EXPORT(n:Spring,pr:setter)
		inline void setSpring(const Spring& value);

		/** @copydoc DistanceJoint::setFlag */
		BS_SCRIPT_EXPORT(n:SetFlag)
		inline void setFlag(DistanceJointFlag flag, bool enabled);

		/** @copydoc DistanceJoint::hasFlag */
		BS_SCRIPT_EXPORT(n:HasFlag)
		inline bool hasFlag(DistanceJointFlag flag) const;

		/** @name Internal
		 *  @{
		 */

		/**	Returns the distance joint that this component wraps. */
		DistanceJoint* _getInternal() const { return static_cast<DistanceJoint*>(mInternal.get()); }

		/** @} */

		/************************************************************************/
		/* 						COMPONENT OVERRIDES                      		*/
		/************************************************************************/
	protected:
		friend class SceneObject;

		/** @copydoc CJoint::createInternal */
		SPtr<Joint> createInternal() override;

		DISTANCE_JOINT_DESC mDesc;

		/************************************************************************/
		/* 								RTTI		                     		*/
		/************************************************************************/
	public:
		friend class CDistanceJointRTTI;
		static RTTITypeBase* getRTTIStatic();
		RTTITypeBase* getRTTI() const override;

	protected:
		CDistanceJoint();// Serialization only
	};

	 /** @} */
}