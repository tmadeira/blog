import React from "react";

import Award from "../components/Award";
import Badge from "../components/Badge";
import Card from "../components/Card";
import Head from "../components/Head";
import Layout from "../components/Layout";
import Section from "../components/Section";
import SectionItem from "../components/SectionItem";

export default function () {
  return (
    <Layout>
      <Head title="Tiago Madeira's Resumé" />

      <Card title="Tiago Madeira" description="Software Engineer" />

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
          description={
            <span>
              Final project:{" "}
              <a href="https://github.com/tmadeira/tcc/">
                Uniform sampling of <em>k</em>-trees for learning Bayesian
                networks
              </a>
            </span>
          }
          subdescription="Supervisor: Prof. Denis Deratani Maua"
          badge={<Badge>2016</Badge>}
        />
      </Section>

      <Section title="Professional Experience">
        <SectionItem
          title="EVAG"
          subtitle="Director & Software Engineer"
          description="Management and software development."
          badge={<Badge type="featured">dec/2014 - current</Badge>}
        />

        <SectionItem
          title="Google"
          subtitle="Software Engineering Intern"
          description="Development of anti-abuse technology."
          subdescription={
            <div>
              Some experience with Go, protocol buffers, and Google
              infra-structure and tools.
              <br />
              Supervisor: Tony Lopes
              <br />
              Belo Horizonte, Brazil
            </div>
          }
          badge={<Badge>dec/2015 - mar/2016</Badge>}
        />

        <SectionItem
          title="Dropbox"
          subtitle="Software Engineering Intern"
          description="Development of continuous integration tools, focus on handling flaky tests."
          subdescription={
            <div>
              Some experience with Python, Postgres, Jenkins, Puppet, shell
              scripting.
              <br />
              Supervisor: Li Haoyi
              <br />
              San Francisco, USA
            </div>
          }
          badge={<Badge>may/2015 - jul/2015</Badge>}
        />

        <SectionItem
          title="Facebook"
          subtitle="Software Engineering Intern"
          description="Development of Facebook applications, focus on products for teenagers."
          subdescription={
            <div>
              Some experience with mobile and web development, Android, React,
              Hack, and other tools.
              <br />
              Supervisor: Dolapo Falola
              <br />
              London, UK
            </div>
          }
          badge={<Badge>jan/2015 - apr/2015</Badge>}
        />

        <SectionItem
          title="imo.im"
          subtitle="Software Engineering Intern"
          description="Development of new imo web application."
          subdescription={
            <div>
              Some experience with client-side web development, AngularJS and
              other tools.
              <br />
              Supervisor: Iskren Chernev
              <br />
              Palo Alto, USA
            </div>
          }
          badge={<Badge>dec/2013 - mar/2014</Badge>}
        />

        <SectionItem
          title="imo.im"
          subtitle="Software Engineering Intern"
          description="Development of audio calls for mobile devices."
          subdescription={
            <div>
              Some experience with network programming, streaming, mobile
              development, cryptography, C/C++, OpenSSL, Android and iPhone.
              <br />
              Supervisor: Patrick Horn
              <br />
              Palo Alto, USA
            </div>
          }
          badge={<Badge>feb/2012 - jul/2012</Badge>}
        />

        <SectionItem
          title="upLexis"
          subtitle="Software Engineering Intern"
          description="Development of a named entity recognizer for a specific kind of document."
          subdescription={
            <div>
              Some experience with large amounts of data, information retrieval,
              natural language processing, machine learning, Java.
              <br />
              Supervisor: Daniel Creao
              <br />
              Sao Paulo, Brazil
            </div>
          }
          badge={<Badge>apr/2010 - aug/2011</Badge>}
        />
      </Section>

      <Section title="Awards">
        <SectionItem
          title="ACM"
          subtitle="Association for Computer Machinery"
          description={
            <ul>
              <Award
                title="Honorable Mention at ACM-ICPC World Finals"
                description="Orlando, USA"
                badge={<Badge>2011</Badge>}
              />
              <Award
                title="Honorable Mention at ACM-ICPC World Finals"
                description="Stockholm, Sweden"
                badge={<Badge>2009</Badge>}
              />
            </ul>
          }
        />

        <SectionItem
          title="SBC"
          subtitle="Brazilian Computer Society"
          description={
            <ul>
              <Award
                title="Silver Medal at ACM-ICPC South America Regional (Maratona de Programação)"
                badge={<Badge>2010</Badge>}
              />
              <Award
                title="Silver Medal at ACM-ICPC South America Regional (Maratona de Programação)"
                badge={<Badge>2008</Badge>}
              />
              <Award
                title="Bronze Medal at Brazilian Olympiad in Informatics (OBI)"
                badge={<Badge>2008</Badge>}
              />
              <Award
                title="Bronze Medal at Brazilian Olympiad in Informatics (OBI)"
                badge={<Badge>2007</Badge>}
              />
              <Award
                title="Gold Medal at Brazilian Olympiad in Informatics (OBI)"
                badge={<Badge>2005</Badge>}
              />
              <Award
                title="Gold Medal at Brazilian Olympiad in Informatics (OBI)"
                badge={<Badge>2004</Badge>}
              />
            </ul>
          }
        />

        <SectionItem
          title="SBM"
          subtitle="Brazilian Mathematical Society"
          description={
            <ul>
              <Award
                title="Silver Medal at Regional Mathematical Olympiad (ORM)"
                badge={<Badge>2007</Badge>}
              />
              <Award
                title="Honorable Mention at Regional Mathematical Olympiad (ORM)"
                badge={<Badge>2006</Badge>}
              />
              <Award
                title="Honorable Mention at Regional Mathematical Olympiad (ORM)"
                badge={<Badge>2005</Badge>}
              />
              <Award
                title="Gold Medal at Regional Mathematical Olympiad (ORM)"
                badge={<Badge>2004</Badge>}
              />
              <Award
                title="Bronze Medal at Regional Mathematical Olympiad (ORM)"
                badge={<Badge>2003</Badge>}
              />
              <Award
                title="Gold Medal at Regional Mathematical Olympiad (ORM)"
                badge={<Badge>2002</Badge>}
              />
              <Award
                title="Honorable Mention at Brazilian Mathematical Olympiad (OBM)"
                badge={<Badge>2002</Badge>}
              />
            </ul>
          }
        />

        <SectionItem
          title="FICOM"
          subtitle="Iberoamerican Federation of Mathematical Competitions"
          description={
            <ul>
              <Award
                title="Bronze Medal at Iberoamerican May Olympiad (Olimpíada de Mayo)"
                badge={<Badge>2005</Badge>}
              />
              <Award
                title="Bronze Medal at Iberoamerican May Olympiad (Olimpíada de Mayo)"
                badge={<Badge>2003</Badge>}
              />
            </ul>
          }
        />
      </Section>

      <Section title="Other Work">
        <SectionItem
          title="Teaching"
          description={
            <ul>
              <Award
                title="Introduction to AI"
                description="Colégio Santa Cruz"
                badge={<Badge type="featured">2019 - current</Badge>}
              />
              <Award
                title="Internet Contemporaneities and Introduction to Computer Programming"
                description="Colégio Ítaca"
                badge={<Badge>2014</Badge>}
              />
            </ul>
          }
        />

        <SectionItem
          title="Open Source Software"
          description={
            <ul>
              <Award
                title="Authored WordPress theme Dolores"
                badge={<Badge>2015</Badge>}
              />
              <Award
                title="Contributed to SilverStripe and Drupal in Google Highly Open Participation Contest"
                badge={<Badge>2008</Badge>}
              />
              <Award
                title="Contributed to the development of webcam 0c45:6260 and image sensor OV7670 in the Microdia driver for Linux"
                badge={<Badge>2008</Badge>}
              />
              <Award
                title="Contributed to Funções ZZ"
                badge={<Badge>2008</Badge>}
              />
            </ul>
          }
          subdescription={
            <div style={{ marginTop: 10 }}>
              Check my GitHub profile at{" "}
              <a href="https://github.com/tmadeira">github.com/tmadeira</a>
            </div>
          }
        />
      </Section>

      <Section title="Additional Education">
        <SectionItem
          title="Game Theory (with distinction)"
          subtitle="Online at Coursera"
          description="Instructors: Matthew O. Jackson (Stanford), Kevin Leyton-Brown (UBC), Yoav Shoham (Stanford)"
          badge={<Badge>2014</Badge>}
        />
        <SectionItem
          title="Cryptography I (with distinction)"
          subtitle="Online at Coursera"
          description="Instructor: Dan Boneh (Stanford)"
          badge={<Badge>2013</Badge>}
        />
        <SectionItem
          title="Programming Challenges"
          subtitle="University of São Paulo (USP)"
          subdescription="Invited for having a good performance at ACM-ICPC."
          badge={<Badge>2011</Badge>}
        />
        <SectionItem
          title="Programming Challenges"
          subtitle="University of São Paulo (USP)"
          badge={<Badge>2010</Badge>}
        />
        <SectionItem
          title="Advanced Computer Programming"
          subtitle="State University of Campinas (UNICAMP)"
          subdescription="Invited for having a good performance at Brazilian Olympiad in Informatics (OBI)."
          badge={<Badge>2006</Badge>}
        />
        <SectionItem
          title="Advanced Computer Programming"
          subtitle="State University of Campinas (UNICAMP)"
          subdescription="Invited for having a good performance at Brazilian Olympiad in Informatics (OBI)."
          badge={<Badge>2005</Badge>}
        />
        <SectionItem
          title="Introduction to Computer Programming"
          subtitle="State University of Campinas (UNICAMP)"
          subdescription="Invited for having a good performance at Brazilian Olympiad in Informatics (OBI)."
          badge={<Badge>2004</Badge>}
        />
      </Section>
    </Layout>
  );
}
