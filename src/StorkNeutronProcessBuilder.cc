/*
StorkNeutronProcessBuilder.cc

Created by:		Liam Russell
Date:			23-02-2012
Modified:       11-03-2013

Source code for StorkNeutronProcessBuilder class.

*/


// Include header file
#include "StorkNeutronProcessBuilder.hh"


// Constructor
StorkNeutronProcessBuilder::StorkNeutronProcessBuilder(G4bool pBC)
:wasActivated(false), periodicBC(pBC)
{
    // Create the physics processes
    theNeutronElastic = new StorkHadronElasticProcess;
    theNeutronInelastic = new StorkNeutronInelasticProcess;
    theNeutronCapture = new StorkHadronCaptureProcess;
    theNeutronFission = new StorkHadronFissionProcess;
    theStepLimiter = new StorkTimeStepLimiter;
    thePeriodicBoundary = new StorkPeriodicBCStepLimiter;
}


// Destructor
StorkNeutronProcessBuilder::~StorkNeutronProcessBuilder()
{
    // Delete the processes
    delete theNeutronElastic;
    delete theNeutronInelastic;
    delete theNeutronCapture;
    delete theNeutronFission;
    delete theStepLimiter;
    delete thePeriodicBoundary;
}


// Build()
// Build the data and models for the neutron processes
void StorkNeutronProcessBuilder::Build()
{
    wasActivated = true;
    StorkHPNeutronBuilder *aHPBuilder;

    // Build the models and data for the neutron processes (all energies)
    std::vector<G4VNeutronBuilder *>::iterator i;
    for(i=theModelCollections.begin(); i!=theModelCollections.end(); i++)
    {
        aHPBuilder = dynamic_cast<StorkHPNeutronBuilder*>(*i);

        // Only build low energy models for the elastic processes
        if(aHPBuilder)
            (*i)->Build(theNeutronElastic);

        (*i)->Build(theNeutronInelastic);
        (*i)->Build(theNeutronCapture);
        (*i)->Build(theNeutronFission);
    }

    // Create the high energy elastic model
    //G4LElastic *theHighElasticModel = new G4LElastic();
    G4DiffuseElastic *theHighElasticModel = new G4DiffuseElastic();
    // Set the minimum and maximum energy limits
    theHighElasticModel->SetMinEnergy(20.0*MeV);
    theHighElasticModel->SetMaxEnergy(20000.*GeV);

    // Register model with elastic process
    theNeutronElastic->RegisterMe(theHighElasticModel);

    // Add processes to the process manager
    G4ProcessManager * theProcMan = G4Neutron::Neutron()->GetProcessManager();

    theProcMan->AddDiscreteProcess(theNeutronElastic);
    theProcMan->AddDiscreteProcess(theNeutronInelastic);
    theProcMan->AddDiscreteProcess(theNeutronCapture);
    theProcMan->AddDiscreteProcess(theNeutronFission);
    theProcMan->AddDiscreteProcess(theStepLimiter);

	// Only add infinite boundary process if flag is set to true
    if(periodicBC)
        theProcMan->AddDiscreteProcess(thePeriodicBoundary);
}



