#include "Pickup.h"

Pickup::Pickup(PickupType pickupType) :
	m_PickupType(pickupType)
{

}

Pickup::~Pickup()
{

}

void Pickup::update(double delta)
{

}

void Pickup::reset()
{

}

PickupType Pickup::getPickupType()
{
	return m_PickupType;
}