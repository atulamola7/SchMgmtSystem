#include "entityDatabase.h"
using namespace std;

EntityDataBase::EntityDataBase()
{
}

EntityDataBase::~EntityDataBase()
{
}

int EntityDataBase::addNewEntity(Entity entity, const std::string& name)
{
}

int EntityDataBase::linkEntity()
{
}

int EntityDataBase::deleteEntity()
{
}

int EntityDataBase::printEntityDetails() const
{
  // Printing Teacher details
  cout << "Printing teacher details: " << endl;
  if(m_allTeachers.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allTeachers.size(); i++)
  {
    cout << "\t" << m_allTeachers[i] << endl;
  }
  // Printing students details
  cout << "Printing student details: " << endl;
  if(m_allStudents.size() == 0)
    cout << "\t!.. NO DATA ..!" << endl;
  for(int i = 0; i < m_allStudents.size(); i++)
  {
    cout << "\t" << m_allStudents[i] << endl;
  }

  return 0;
}

int EntityDataBase::findEntity() const
{
}
