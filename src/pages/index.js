import React from 'react';

import Badge from '../components/Badge';
import Card from '../components/Card';
import Head from '../components/Head';
import Layout from '../components/Layout';
import Section from '../components/Section';
import SectionItem from '../components/SectionItem';
import TextContent from '../components/TextContent';

export default function() {
  return (
    <Layout>
      <Head />

      <Card
        title="Tiago Madeira"
        description="Software Engineer"
      />

      <TextContent>
        <p>Computer scientist, studying probabilistic AI. Self-employed software engineer after internships at Google, Facebook, Dropbox, and imo.im. Former ACM-ICPC contestant.</p>
      </TextContent>

      <Section title="Education">
        <SectionItem
          title="M.S. Computer Science"
          subtitle="University of São Paulo"
          description="Area: Artificial Intelligence (Probabilistic Graphical Models)"
          badge={<Badge type="featured">in progress</Badge>}
        />

        <SectionItem
          title="B.S. Computer Science"
          subtitle="University of São Paulo"
          description={<span>Final project: <a href="https://github.com/tmadeira/tcc/">Uniform sampling of <em>k</em>-trees for learning Bayesian networks</a></span>}
          subdescription="Supervisor: Prof. Denis Deratani Maua"
          badge={<Badge>2016</Badge>}
        />
      </Section>

      <Section title="Professional Experience">
        <SectionItem
          title="EVAG"
          subtitle="Director & Software Engineer"
          badge={<Badge type="featured">apr/2016 - current</Badge>}
        />

        <SectionItem
          title="Google"
          subtitle="Software Engineering Intern"
          description="Some experience with Go (Golang), protocol buffers, and Google infra-structure and tools."
          subdescription={<span>Supervisor: Tony Lopes<br />Belo Horizonte, Brazil</span>}
          badge={<Badge>dec/2015 - mar/2016</Badge>}
        />
      </Section>
    </Layout>
  );
};
